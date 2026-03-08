/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:11:47 by codespace         #+#    #+#             */
/*   Updated: 2026/03/08 13:07:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_last_meal_time(t_philosopher *philosopher)
{
	long			timestamp_ms;

	pthread_mutex_lock(&philosopher->meal_mutex);
	timestamp_ms = get_timestamp_ms();
	philosopher->last_meal = timestamp_ms;
	pthread_mutex_unlock(&philosopher->meal_mutex);
}

void	set_death(t_simulation *simulation, int id)
{
	pthread_mutex_lock(&simulation->state_mutex);
	simulation->flags.philosopher_died = id;
	pthread_mutex_unlock(&simulation->state_mutex);
}

void    set_all_philosophers_full(t_simulation *simulation)
{
    pthread_mutex_lock(&simulation->state_mutex);
    simulation->flags.all_philosophers_full = 1;
    pthread_mutex_unlock(&simulation->state_mutex);
}

void    set_increment_meals_eaten(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->meal_mutex);
    ++philosopher->meals_eaten;
    pthread_mutex_unlock(&philosopher->meal_mutex);
}
