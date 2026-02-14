/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/02/14 23:37:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void static	mutex_var_init(t_simulation *simulation)
{
	simulation->death = 0;
}

int	simulation_mutex_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&simulation->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&simulation->print_mutex);
		return (1);
	}
	mutex_var_init(simulation);
	return (0);
}

int	fork_mutex_init(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		return (1);
	return (0);
}
