/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_termination.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 13:43:03 by codespace        ###   ########.fr       */
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
