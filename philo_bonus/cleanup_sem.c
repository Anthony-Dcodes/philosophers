/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_sem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:13:14 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 12:13:19 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	unlink_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
	sem_unlink(SEM_SEATS);
}

void	close_semaphores(t_simulation *sim)
{
	sem_close(sim->fork_semaphore);
	sem_close(sim->meal_semaphore);
	sem_close(sim->print_semaphore);
	sem_close(sim->state_semaphore);
	sem_close(sim->seats_semaphore);
}
