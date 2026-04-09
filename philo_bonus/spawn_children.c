/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:43:03 by codespace         #+#    #+#             */
/*   Updated: 2026/04/09 11:50:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int spawn_children(t_simulation simulation, t_philosopher philosopher, pid_t *pids)
{
    int i;
    pid_t   pid;
    int     ret;

    i = 0;
    pid = getpid();
    ret = ERR_OK;
    while (i < simulation.n_philosophers && pid != 0) // spawn all child proceses
	{
		pid = fork();
		printf("new process spawned: %d, returned pidid: %d, iterator: %d\n", getpid(), (int)(pid), i);
		if (pid < 0)
            return (ERR_FORK);
		else if (pid == 0)
		{
			printf("I am child process! %d\n", getpid());
			ret = initialize_philosopher_thread(&philosopher, i);
			if (ret != ERR_OK)
				goto subprocess_exit;
			monitoring(&simulation, &philosopher);
			log_end_of_simulation(&simulation, &ret);
			printf("Exiting child: %d, id: %d, meals_eaten: %d, to_eat: %d\n", (int)getpid(), philosopher.id, simulation.n_times_must_eat, philosopher.meals_eaten);
			subprocess_exit:
				subprocess_cleanup(&philosopher, pids);
				exit(ret);

		}
		else
			pids[i] = pid;
		++i;
	}
    return (ERR_OK);
}
