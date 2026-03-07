/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:37:00 by codespace         #+#    #+#             */
/*   Updated: 2026/03/07 11:02:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_loop(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	printf("last meal set:\n");
	printf("amount of times philos must eat: %d\n", philosopher->sim->n_times_must_eat);
	printf("philos died: %s", !philosopher->sim->flags.philosopher_died);
	if (philosopher->sim->n_philosophers == 1)
	{
		printf("handle single philosopher\n");
		handle_single_philosopher(philosopher);
        return (NULL);
	}
	else if (philosopher->sim->n_times_must_eat)
		while (get_meals_eaten(philosopher) < philosopher->sim->n_times_must_eat && !get_death(philosopher->sim))
		{
			printf("main loop:\n");
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
			set_increment_meals_eaten(philosopher);
		}
	else
		while (!philosopher->sim->flags.philosopher_died)
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
