/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 07:46:34 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <fcntl.h>
#include "structs.h"
#include "error.h"
#include "macros.h"

int	semaphore_init(t_simulation *simulation)
{
	simulation->print_semaphore = sem_open(SEM_PRINT, O_CREAT, 0666, 1);
	if (simulation->print_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->state_semaphore = sem_open(SEM_STATE, O_CREAT, 0666, 1);
	if (simulation->state_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->meal_semaphore = sem_open(SEM_MEAL, O_CREAT, 0666, 1);
	if (simulation->meal_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->fork_semaphore = sem_open(SEM_FORKS, O_CREAT, 0666,
			simulation->n_philosophers);
	if (simulation->fork_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->seats_semaphore = sem_open(SEM_SEATS, O_CREAT, 0666,
			simulation->n_philosophers / 2);
	if (simulation->seats_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->philo_full_semaphore = sem_open(SEM_PHILO_FULL, O_CREAT, 0666, 0);
	if (simulation->philo_full_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->destroy_semaphore = sem_open(SEM_DESTROY, O_CREAT, 0666, 0);
	if (simulation->destroy_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->death_print_semaphore = sem_open(SEM_DEATH_PRINT, O_CREAT, 0666, 1);
	if (simulation->death_print_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	return (ERR_OK);
}
