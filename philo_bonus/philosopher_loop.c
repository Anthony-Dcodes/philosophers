/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:37:00 by codespace         #+#    #+#             */
/*   Updated: 2026/04/26 12:34:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_loop(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->sim->n_philosophers == 1)
		handle_single_philosopher(philosopher);
	else if (philosopher->sim->n_times_must_eat)
	{
		while (get_meals_eaten(philosopher) < philosopher->sim->n_times_must_eat
			&& !get_death(philosopher->sim))
		{
			think_eat_sleep(philosopher);
			set_increment_meals_eaten(philosopher);
		}
	}
	else
	{
		while (!get_death(philosopher->sim))
			think_eat_sleep(philosopher);
	}
	return (NULL);
}
