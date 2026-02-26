/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/02/25 23:36:00 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_mutex_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL))
		return (1);
	simulation->flags.print_mutex_created = 1;
	if (pthread_mutex_init(&simulation->death_mutex, NULL))
		return (1);
	simulation->flags.death_mutex_created = 1;
	return (0);
}

int	fork_mutex_init(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		return (1);
	return (0);
}
