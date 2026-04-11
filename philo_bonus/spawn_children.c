/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:43:03 by codespace         #+#    #+#             */
/*   Updated: 2026/04/11 20:54:39 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	spawn_children(t_simulation *simulation,
				t_philosopher *philosopher, pid_t **pids)
{
	int		i;
	pid_t	pid;
	int		ret;

	i = 0;
	pid = getpid();
	ret = ERR_OK;
	while (i < simulation->n_philosophers && pid != 0)
	{
		pid = fork();
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

void	children_execution(t_philosopher *philosopher,
						t_simulation *simulation, int i, pid_t **pids)
{
	int	ret;

	ret = ERR_OK;
	ret = initialize_philosopher_thread(philosopher, i);
	if (ret != ERR_OK)
		goto subprocess_exit;
	monitoring(simulation, philosopher);
	subprocess_exit:
	if (philosopher->sim->flags.thread_created)
	{
		printf("About to join thread on process: %d, philo id: %d\n", getpid(), philosopher->id);
		pthread_join(philosopher->thread, NULL);
	}
	log_end_of_simulation(philosopher, &ret);
	close_semaphores(philosopher->sim);
	printf("sems closed\n");
	free(*pids);
	exit(ret);
}
