/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:13:14 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 07:17:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "structs.h"

void	unlink_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
	sem_unlink(SEM_SEATS);
	sem_unlink(SEM_PHILO_FULL);
	sem_unlink(SEM_DESTROY);
	sem_unlink(SEM_DEATH_PRINT);
}

void	close_semaphores(t_simulation *sim)
{
	sem_close(sim->fork_semaphore);
	sem_close(sim->meal_semaphore);
	sem_close(sim->print_semaphore);
	sem_close(sim->state_semaphore);
	sem_close(sim->seats_semaphore);
	sem_close(sim->philo_full_semaphore);
	sem_close(sim->destroy_semaphore);
	sem_close(sim->death_print_semaphore);
}
