/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:37:00 by codespace         #+#    #+#             */
/*   Updated: 2026/04/25 22:42:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_loop(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	set_last_meal_time(philosopher);
	if (philosopher->sim->n_philosophers == 1)
	{
		handle_single_philosopher(philosopher);
		return (NULL);
	}
	if (philosopher->id % 2)
		usleep(1000);
	if (philosopher->sim->n_times_must_eat)
	{
		while (get_meals_eaten(philosopher) < philosopher->sim->n_times_must_eat
			&& !get_death(philosopher->sim))
			think_eat_sleep(philosopher);
	}
	else
		while (!philosopher->sim->flags.philosopher_died)
			think_eat_sleep(philosopher);
	return (NULL);
}

void	handle_single_philosopher(t_philosopher *philosopher)
{
	thinking(philosopher);
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	log_general(philosopher, FORK);
	usleep(philosopher->sim->time_to_die * 1000);
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
}

void	think_eat_sleep(t_philosopher *philosopher)
{
	thinking(philosopher);
	eating(philosopher);
	if (philosopher->sim->n_times_must_eat)
		set_increment_meals_eaten(philosopher);
	sleeping(philosopher);
}
