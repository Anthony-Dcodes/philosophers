/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/12 20:34:10 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	int				i;
	t_philosopher	*philosophers;
	t_fork			*forks;

	i = 0;
	if (parser_args(argc, argv, &simulation))
		return (1);
	printf("Parser done\n");
	if (simulation_mutex_init(&simulation))
		return (1);
	philosophers = malloc(sizeof(t_philosopher) * simulation.n_philosophers);
	forks = malloc(sizeof(t_fork) * simulation.n_philosophers);
	// Handle malloc errors
	while (i < simulation.n_philosophers)
	{
		fork_mutex_init(&forks[i]);
		++i;
	}
	i = 0;
	while (i < simulation.n_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].right_fork = &forks[i];
		if (i == simulation.n_philosophers - 1)
			philosophers[i].left_fork = &forks[0];
		else
			philosophers[i].left_fork = &forks[i + 1];
		philosophers[i].sim = &simulation;
		pthread_create(&philosophers[i].thread, NULL, philo_loop, &philosophers[i]);
		++i;
	}
	i = 0;
	while (i < simulation.n_philosophers)
	{
		pthread_join(&philosophers->thread[i], NULL);
		++i;
	}
	free(philosophers);
	free(forks);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	thinking(philosopher);
	eating(philosopher);
	sleeping(philosopher);
	return (NULL);
}
