/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/03/10 21:14:08 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	simulation_sem_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL))
		return (ERR_MUTEX);
	simulation->flags.print_mutex_created = 1;
	if (pthread_mutex_init(&simulation->state_mutex, NULL))
		return (ERR_MUTEX);
	simulation->flags.state_mutex_created = 1;
	return (0);
}

int	fork_sem_init(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL))
		return (ERR_MUTEX);
	return (0);
}

int	meal_sem_init(t_philosopher *philosopher)
{
	if (pthread_mutex_init(&philosopher->meal_mutex, NULL))
		return (ERR_MUTEX);
	return (0);
}
