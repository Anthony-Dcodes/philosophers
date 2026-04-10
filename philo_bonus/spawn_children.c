/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:43:03 by codespace         #+#    #+#             */
/*   Updated: 2026/04/10 19:00:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int spawn_children(t_simulation *simulation, t_philosopher *philosopher, pid_t **pids)
{
    int i;
    pid_t   pid;
    int     ret;

    i = 0;
    pid = getpid();
    ret = ERR_OK;
    while (i < simulation->n_philosophers && pid != 0) // spawn all child proceses
	{
		pid = fork();
		printf("new process spawned: %d, returned pidid: %d, iterator: %d\n", getpid(), (int)(pid), i);
		if (pid < 0)
            return (ERR_FORK);
		else if (pid == 0)
            children_execution(philosopher, simulation, i, pids);
		else
			(*pids)[i] = pid;
		++i;
	}
    return (ERR_OK);
}

void    children_execution(t_philosopher *philosopher, t_simulation *simulation, int i, pid_t **pids)
{
    int ret;

    ret = ERR_OK;
    printf("I am child process! %d\n", getpid());
    ret = initialize_philosopher_thread(philosopher, i);
    if (ret != ERR_OK)
        goto subprocess_exit;
    monitoring(simulation, philosopher);
    log_end_of_simulation(philosopher, &ret);
    printf("Exiting child: %d, id: %d, meals_eaten: %d, to_eat: %d\n", (int)getpid(), philosopher->id, simulation->n_times_must_eat, philosopher->meals_eaten);
    subprocess_exit:
        printf("subprocess_exit started\n");
        subprocess_cleanup(philosopher, *pids);
        printf("after subprocess_cleanup\n");
        exit(ret);
}
