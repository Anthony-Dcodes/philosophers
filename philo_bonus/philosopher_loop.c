/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:37:00 by codespace         #+#    #+#             */
/*   Updated: 2026/04/09 14:34:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_loop(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	if (philosopher->sim->n_philosophers == 1)
	{
		handle_single_philosopher(philosopher);
        return (NULL);
	}
	else if (philosopher->sim->n_times_must_eat)
		{
			while (get_meals_eaten(philosopher) < philosopher->sim->n_times_must_eat && !get_death(philosopher->sim))
			{
				thinking(philosopher);
				eating(philosopher);
				sleeping(philosopher);
				set_increment_meals_eaten(philosopher);
			}
		}
	else
		while (!get_death(philosopher->sim))
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
		}
	return (NULL);
}

void handle_single_philosopher(t_philosopher *philosopher)
{
    thinking(philosopher);
    sem_wait(philosopher->sim->fork_semaphore);
    log_general(philosopher, FORK);
    usleep(philosopher->sim->time_to_die * 1000);
    sem_post(philosopher->sim->fork_semaphore);
}
