/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/25 23:17:44 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	t_fork			*forks;
	int				i;

	i = 0;
	init_flags(&simulation.flags);
	if (parser_args(argc, argv, &simulation))
		return (ERR_PARSE);
	if (simulation_mutex_init(&simulation))
		return (ERR_MUTEX);
	philosophers = malloc(sizeof(t_philosopher) * simulation.n_philosophers);
	if (!philosophers)
		return (ERR_MEMORY);
	forks = malloc(sizeof(t_fork) * simulation.n_philosophers);
	if (!forks)
	{
		clean_up(philosophers, NULL, &simulation);
		return (ERR_MEMORY);
	}
	while (i < simulation.n_philosophers)
	{
		if (fork_mutex_init(&forks[i]))
		{
			clean_up(philosophers, forks, &simulation);
			return (ERR_MUTEX);
		}
		++simulation.flags.n_forks_created;
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
		{
			clean_up(philosophers, forks, &simulation);
			return (ERR_THREAD);
		}
		++simulation.flags.n_threads_created;
		++i;
	}
	printf("Start death monitoring:\n");
	while (!simulation.flags.death && !simulation.flags.all_philosophers_full)
	{
		usleep(1000);
		death_monitoring(philosophers, &simulation);
		all_philosophers_full_monitoring(philosophers, &simulation);
	}
	if (simulation.flags.death)
		log_death(&simulation);
	else if (simulation.flags.all_philosophers_full)
		log_all_philosophers_ate(&simulation);
	printf("Cleanup next:\n");
	clean_up(philosophers, forks, &simulation);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	if (philosopher->sim->n_times_must_eat)
		while (i < philosopher->sim->n_times_must_eat && !philosopher->sim->flags.death)
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
			++philosopher->meals_eaten;
			++i;
		}
	else
		while (!philosopher->sim->flags.death)
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
			++philosopher->meals_eaten;
			++i;
		}
	return (NULL);
}

void	death_monitoring(t_philosopher *philosophers, t_simulation *sim)
{
	int				i;
	long			current_time_ms;

	i = 0;
	while (i < sim->n_philosophers)
	{
		current_time_ms = get_timestamp_ms();
		//printf("Monitor philosopher: %d, time: %ld\n", i + 1, current_time_ms);
		if (current_time_ms - philosophers[i].last_meal >= sim->time_to_die)
		{
			pthread_mutex_lock(&sim->death_mutex);
			sim->flags.death = philosophers[i].id;
			pthread_mutex_unlock(&sim->death_mutex);
			printf("Death detected: philosophre: %d, current time: %ld, last meal: %ld\n", i + 1, current_time_ms, philosophers[i].last_meal);
			return ;
		}
		++i;
	}
}

void	all_philosophers_full_monitoring(t_philosopher *philosophers, t_simulation *sim)
{
	int				i;
	int				all_philosophers_full;
	int				meals_eaten;
	int				n_times_muse_eat;

	i = 0;
	all_philosophers_full = 1;
	n_times_muse_eat = sim->n_times_must_eat;
	if (n_times_muse_eat)
	{
		while (i < sim->n_philosophers)
		{
			meals_eaten = philosophers[i].meals_eaten;
			if (meals_eaten < n_times_muse_eat)
				all_philosophers_full = 0;
			++i;
		}
		if (all_philosophers_full)
		{
			sim->flags.all_philosophers_full = 1;
			return ;
		}
	}
	return ;
}
