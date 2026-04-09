/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:09:43 by codespace         #+#    #+#             */
/*   Updated: 2026/04/09 09:18:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int    monitor_children(pid_t *pids, t_simulation simulation)
{
    int i;
    int status;
    int full_philos;
    
    i = 0;
    full_philos = 0;
    while (full_philos != simulation.n_philosophers)
	{
		if (i == simulation.n_philosophers)
			i = 0;
		usleep(100000);
		printf("Main process monitoring i: %d, full_philos: %d, n_philos: %d\n", i, full_philos, simulation.n_philosophers);
		if (waitpid(pids[i], &status, WNOHANG) > 0)
		{
			printf("child exited: %d, iterator i: %d\n", pids[i], i);
			pids[i] = 0;
			if (WIFEXITED(status) && WEXITSTATUS(status) > 0)
			{
				terminate_children(pids, simulation);
				return (-1);
			}
			else
				++full_philos;
		}
		++i;
	}
    return (full_philos);    
}

void    terminate_children(pid_t *pids, t_simulation simulation)
{
    int j;

    j = 0;
    while (j < simulation.n_philosophers)
    {
        printf("killing process: %d\n", pids[j]);
        if (pids[j] != 0)
        {
            kill(pids[j], SIGKILL);
            waitpid(pids[j], NULL, 0);
        }
        ++j;
    }
    return ;
}
