/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:55:19 by codespace         #+#    #+#             */
/*   Updated: 2026/04/11 20:41:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	monitoring(t_simulation *simulation, t_philosopher *philosopher)
{
	while (!get_death(simulation) && !get_philosopher_full(simulation))
	{
		usleep(1000);
		death_monitoring(philosopher, simulation);
		philosopher_full_monitoring(philosopher, simulation);
	}
}

void	death_monitoring(t_philosopher *philosopher, t_simulation *sim)
{
	long	current_time_ms;

	current_time_ms = get_timestamp_ms();
	if (current_time_ms - get_last_meal(philosopher) >= sim->time_to_die)
		set_death(sim, philosopher->id);
	return ;
}

void	philosopher_full_monitoring(t_philosopher *philosopher,
									t_simulation *sim)
{
	int	meals_eaten;
	int	n_times_must_eat;

	n_times_must_eat = sim->n_times_must_eat;
	meals_eaten = get_meals_eaten(philosopher);
	if (meals_eaten >= n_times_must_eat && n_times_must_eat)
		set_philosopher_full(philosopher->sim);
	return ;
}
