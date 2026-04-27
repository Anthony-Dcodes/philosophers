/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:22:01 by codespace         #+#    #+#             */
/*   Updated: 2026/04/27 13:47:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "structs.h"

int	get_death(t_simulation *simulation)
{
	int	value;

	sem_wait(simulation->state_semaphore);
	value = simulation->flags.philosopher_died;
	sem_post(simulation->state_semaphore);
	return (value);
}

int	get_philosopher_full(t_simulation *simulation)
{
	int	value;

	sem_wait(simulation->state_semaphore);
	value = simulation->flags.philosopher_full;
	sem_post(simulation->state_semaphore);
	return (value);
}

long	get_last_meal(t_philosopher *philosopher)
{
	long	value;

	sem_wait(philosopher->sim->meal_semaphore);
	value = philosopher->last_meal;
	sem_post(philosopher->sim->meal_semaphore);
	return (value);
}

int	get_meals_eaten(t_philosopher *philosopher)
{
	int	value;

	sem_wait(philosopher->sim->meal_semaphore);
	value = philosopher->meals_eaten;
	sem_post(philosopher->sim->meal_semaphore);
	return (value);
}
