/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/04/08 15:44:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	unlink_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
	sem_unlink(SEM_END);
	sem_unlink(SEM_SEATS);
}

void	close_semaphores(t_simulation *sim)
{
	sem_close(sim->fork_semaphore);
	sem_close(sim->meal_semaphore);
	sem_close(sim->print_semaphore);
	sem_close(sim->state_semaphore);
	sem_close(sim->end_simulation_semaphore);
	sem_close(sim->seats_semaphore);
}

void	subprocess_cleanup(t_philosopher *philosopher)
{
	close_semaphores(philosopher->sim);
	if (philosopher->sim->flags.thread_created)
		pthread_join(philosopher->thread, NULL);
	return ;
}
