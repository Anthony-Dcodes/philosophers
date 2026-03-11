/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 23:02:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	cleanup_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
}

void	clean_up(t_simulation *sim)
{
	sem_close(sim->fork_semaphore);
	sem_close(sim->meal_semaphore);
	sem_close(sim->print_semaphore);
	sem_close(sim->state_semaphore);
	cleanup_semaphores();
}
