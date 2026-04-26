/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:11:47 by codespace         #+#    #+#             */
/*   Updated: 2026/04/11 20:51:48 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_last_meal_time(t_philosopher *philosopher)
{
	long	timestamp_ms;

	sem_wait(philosopher->sim->meal_semaphore);
	timestamp_ms = get_timestamp_ms();
	philosopher->last_meal = timestamp_ms;
	sem_post(philosopher->sim->meal_semaphore);
}

void	set_death(t_simulation *simulation, int id)
{
	sem_wait(simulation->state_semaphore);
	simulation->flags.philosopher_died = id;
	sem_post(simulation->state_semaphore);
}

void	set_philosopher_full(t_simulation *simulation)
{
	sem_wait(simulation->state_semaphore);
	simulation->flags.philosopher_full = 1;
	sem_post(simulation->state_semaphore);
}

void	set_increment_meals_eaten(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim->meal_semaphore);
	++philosopher->meals_eaten;
	sem_post(philosopher->sim->meal_semaphore);
}
