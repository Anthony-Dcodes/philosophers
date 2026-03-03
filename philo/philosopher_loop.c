/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:37:00 by codespace         #+#    #+#             */
/*   Updated: 2026/03/03 16:42:10 by codespace        ###   ########.fr       */
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
		while (philosopher->meals_eaten < philosopher->sim->n_times_must_eat && !philosopher->sim->flags.death)
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
			++philosopher->meals_eaten;
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

void handle_single_philosopher(t_philosopher *philosopher)
{
    thinking(philosopher);
    pthread_mutex_lock(&philosopher->left_fork->mutex);
    log_general(philosopher, FORK);
    usleep(philosopher->sim->time_to_die * 1000);
    pthread_mutex_unlock(&philosopher->left_fork->mutex);
}