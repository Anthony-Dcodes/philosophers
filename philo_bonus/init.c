/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:59:01 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 21:31:28 by advorace         ###   ########.fr       */
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
		philosophers[i].meals_eaten = 0;
		philosophers[i].right_fork = &forks[i];
		if (i == simulation->n_philosophers - 1)
			philosophers[i].left_fork = &forks[0];
		else
			philosophers[i].left_fork = &forks[i + 1];
		philosophers[i].sim = simulation;
		ret = pthread_create(&philosophers[i].thread, NULL, philosopher_loop, &philosophers[i]);
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
