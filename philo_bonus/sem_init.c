/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/03/10 23:19:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	simulation_sem_init(t_simulation *simulation)
{
	simulation->print_semaphore = sem_open(SEM_PRINT, O_CREAT, 0666, 1);
	if (simulation->print_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.print_semaphore_created = 1;
	simulation->state_semaphore = sem_open(SEM_STATE, O_CREAT, 0666, 1);
	if (simulation->state_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.state_semaphore_created = 1;
	simulation->meal_semaphore = sem_open(SEM_MEAL, O_CREAT, 0666, 1);
	if (simulation->meal_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.meal_semaphore_created;
	simulation->fork_semaphore = sem_open(SEM_FORKS, O_CREAT, 0666, simulation->n_philosophers);
	if (simulation->fork_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.fork_semaphore_created;
	return (0);
}
