/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_termination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 07:49:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "structs.h"
#include "signal.h"

void	terminate_children(pid_t **pids, t_simulation *simulation)
{
	int	j;

	j = 0;
	while (j < simulation->n_philosophers)
	{
		if ((*pids)[j] != 0)
		{
			kill((*pids)[j], SIGKILL);
			waitpid((*pids)[j], NULL, 0);
			(*pids)[j] = 0;
		}
		++j;
	}
	return ;
}

int	reap_pid_terminate_rest(pid_t **pids, t_simulation *simulation,
							int i, int *full_philos)
{
	int	status;

	status = 0;
	if (waitpid((*pids)[i], &status, WNOHANG) > 0)
	{
		(*pids)[i] = 0;
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			++(*full_philos);
		else
		{
			terminate_children(pids, simulation);
			return (1);
		}
	}
	return (0);
}

void	activate_child_cleanup(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->n_philosophers)
	{
		sem_post(sim->destroy_semaphore);
		++i;
	}
}
