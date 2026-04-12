/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/04/12 12:30:52 by advorace         ###   ########.fr       */
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

void	free_memory(pid_t *pids)
{
	free(pids);
	pids = NULL;
}

void	terminate_children(pid_t **pids, t_simulation *simulation)
{
	int	j;

	j = 0;
	while (j < simulation->n_philosophers)
	{
		if ((*pids)[j] != 0)
		{
			printf("killing process: %d\n", (*pids)[j]);
			kill((*pids)[j], SIGKILL);
			waitpid((*pids)[j], NULL, 0);
			(*pids)[j] = 0;
		}
		++j;
	}
	return ;
}
