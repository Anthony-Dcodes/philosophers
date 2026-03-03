/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:55:19 by codespace         #+#    #+#             */
/*   Updated: 2026/03/03 15:58:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    monitoring(t_simulation *simulation, t_philosopher *philosophers)
{
    while (!simulation->flags.death && !simulation->flags.all_philosophers_full)
	{
		usleep(1000);
		death_monitoring(philosophers, simulation);
		philosophers_full_monitoring(philosophers, simulation);
	}
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