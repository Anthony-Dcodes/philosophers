/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:22:01 by codespace         #+#    #+#             */
/*   Updated: 2026/04/14 14:45:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_death(t_simulation *simulation)
{
	int	value;

	pthread_mutex_lock(&simulation->state_mutex);
	value = simulation->flags.philosopher_died;
	pthread_mutex_unlock(&simulation->state_mutex);
	return (value);
}

int	get_all_philosophers_full(t_simulation *simulation)
{
	int	value;

	pthread_mutex_lock(&simulation->state_mutex);
	value = simulation->flags.all_philosophers_full;
	pthread_mutex_unlock(&simulation->state_mutex);
	return (value);
}

long	get_last_meal(t_philosopher *philosopher)
{
	long	value;

	pthread_mutex_lock(&philosopher->meal_mutex);
	value = philosopher->last_meal;
	pthread_mutex_unlock(&philosopher->meal_mutex);
	return (value);
}

int	get_meals_eaten(t_philosopher *philosopher)
{
	int	value;

	pthread_mutex_lock(&philosopher->meal_mutex);
	value = philosopher->meals_eaten;
	pthread_mutex_unlock(&philosopher->meal_mutex);
	return (value);
}
