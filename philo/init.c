/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:59:01 by advorace          #+#    #+#             */
/*   Updated: 2026/03/03 15:27:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_flags(t_flags *flags)
{
	memset(flags, 0, sizeof(t_flags));
}

int	initialize_philosophers_threads(t_philosopher *philosophers, t_simulation *simulation, t_fork *forks)
{
	int	i;
	int	ret;

	i = 0;
	ret = ERR_OK;
	while (i < simulation->n_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].right_fork = &forks[i];
		if (i == simulation->n_philosophers - 1)
			philosophers[i].left_fork = &forks[0];
		else
			philosophers[i].left_fork = &forks[i + 1];
		philosophers[i].sim = simulation;
		ret = pthread_create(&philosophers[i].thread, NULL, philo_loop, &philosophers[i]);
		if (ret != ERR_OK)
		{
			ret = ERR_THREAD;
			return (ret);
		}
		++simulation->flags.n_threads_created;
		++i;
	}
	return (ret);
}

int	perfom_mallocs_initialize_mutexes(t_simulation *simulation, t_philosopher **philosophers, t_fork **forks)
{
	int	i;
	int	ret;

	i = 0;
	ret = ERR_OK;
	ret = simulation_mutex_init(simulation);
	if (ret != ERR_OK)
		return (ret);
	*philosophers = malloc(sizeof(t_philosopher) * simulation->n_philosophers);
	if (!philosophers)
		return (ERR_MEMORY);
	*forks = malloc(sizeof(t_fork) * simulation->n_philosophers);
	if (!forks)
		return (ERR_MEMORY);
	while (i < simulation->n_philosophers)
	{
		ret = fork_mutex_init(&(*forks)[i]);
		if (ret != ERR_OK)
			return (ERR_MUTEX);
		++simulation->flags.n_forks_created;
		ret = meal_mutex_init(&(*philosophers)[i]);
		if (ret != ERR_OK)
			return (ERR_MUTEX);
		++simulation->flags.n_meal_mutex_created;
		++i;
	}
	return (ret);
}
