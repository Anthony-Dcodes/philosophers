/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/04/07 13:43:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	semaphore_init(t_simulation *simulation)
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
	simulation->flags.meal_semaphore_created = 1;
	simulation->fork_semaphore = sem_open(SEM_FORKS, O_CREAT, 0666, simulation->n_philosophers);
	if (simulation->fork_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.fork_semaphore_created = 1;
	simulation->end_simulation_semaphore = sem_open(SEM_END, O_CREAT, 0666, 0);
	if (simulation->end_simulation_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.end_simulation_semaphore_created = 1;
	return (ERR_OK);
}
