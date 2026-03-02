/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/03/02 11:51:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_mutex_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL))
		return (ERR_MUTEX);
	simulation->flags.print_mutex_created = 1;
	if (pthread_mutex_init(&simulation->death_mutex, NULL))
		return (ERR_MUTEX);
	simulation->flags.death_mutex_created = 1;
	return (0);
}

int	fork_mutex_init(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		return (ERR_MUTEX);
	return (0);
}
