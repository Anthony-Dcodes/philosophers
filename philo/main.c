/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/03/03 15:52:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	t_fork			*forks;
	int				ret;

	ret = ERR_OK;
	init_flags(&simulation.flags);
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers, &forks);
	if (ret != ERR_OK)
		goto cleanup;
	ret = initialize_philosophers_threads(philosophers, &simulation, forks);
	if (ret != ERR_OK)
		goto cleanup;
	while (!simulation.flags.death && !simulation.flags.all_philosophers_full)
	{
		usleep(1000);
		death_monitoring(philosophers, &simulation);
		philosophers_full_monitoring(philosophers, &simulation);
	}
	log_end_of_simulation(&simulation);
	cleanup:
		clean_up(philosophers, forks, &simulation);
		return (ret);
}

void	*philo_loop(void *arg)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	if (philosopher->sim->n_philosophers == 1)
	{
		thinking(philosopher);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, FORK);
		usleep(philosopher->sim->time_to_die * 1000);
		pthread_mutex_unlock(&philosopher->left_fork->mutex);
		return (NULL);
	}
	else if (philosopher->sim->n_times_must_eat)
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
			return ;
		}
		++i;
	}
}

void	philosophers_full_monitoring(t_philosopher *philosophers, t_simulation *sim)
{
	int				i;
	int				all_philosophers_full;
	int				meals_eaten;
	int				n_times_must_eat;

	i = 0;
	all_philosophers_full = 1;
	n_times_must_eat = sim->n_times_must_eat;
	if (n_times_must_eat)
	{
		while (i < sim->n_philosophers)
		{
			meals_eaten = philosophers[i].meals_eaten;
			if (meals_eaten < n_times_must_eat)
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
