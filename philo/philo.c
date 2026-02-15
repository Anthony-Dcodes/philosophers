/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/15 16:18:10 by advorace         ###   ########.fr       */
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
	if (simulation_mutex_init(&simulation))
		return (1);
	philosophers = malloc(sizeof(t_philosopher) * simulation.n_philosophers);
	if (!philosophers)
		return (clean_up(philosophers, forks));
	forks = malloc(sizeof(t_fork) * simulation.n_philosophers);
	if (!forks)
		return (clean_up(philosophers, forks));
	// Handle malloc errors
	while (i < simulation.n_philosophers)
	{
		if (fork_mutex_init(&forks[i]))
			return (clean_up(philosophers, forks));
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
		if (pthread_create(&philosophers[i].thread, NULL, philo_loop, &philosophers[i]))
			return (clean_up(philosophers, forks));
		++i;
	}
	while (!simulation.death)
		death_monitoring(philosophers, simulation);
	log_death(simulation.death);
	while (i < simulation.n_philosophers)
	{
		if (pthread_join(&philosophers->thread[i], NULL))
			return (clean_up(philosophers, forks));
		++i;
	}
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

void	death_monitoring(t_philosopher *philosophers, t_simulation sim)
{
	int				i;
	struct timeval	tp;
	long			current_time_ms;

	usleep(100);
	i = 0;
	gettimeofday(&tp, NULL);
	current_time_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	while (i < sim.n_philosophers)
	{
		if (current_time_ms - philosophers[i].last_meal >= sim.time_to_die)
			sim.death = philosophers[i].id;
		++i;
	}
}
