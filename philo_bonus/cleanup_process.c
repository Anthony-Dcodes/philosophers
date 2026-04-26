/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:12:51 by advorace          #+#    #+#             */
/*   Updated: 2026/04/11 20:34:39 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	subprocess_cleanup(t_philosopher *philosopher, pid_t *pids)
{
	printf("thread created?: %d\n", philosopher->sim->flags.thread_created);
	printf("thread value: %lu\n", (unsigned long)philosopher->thread);
	if (philosopher->sim->flags.thread_created)
	{
		printf("About to join thread\n");
		pthread_join(philosopher->thread, NULL);
	}
	printf("thread joined\n");
	close_semaphores(philosopher->sim);
	printf("sems closed\n");
	free(pids);
	pids = NULL;
	return ;
}

void	main_process_cleanup(pid_t *pids, t_simulation *simulation)
{
	if (simulation->flags.pids_mallocked)
	{
		terminate_children(&pids, simulation);
		free_memory(pids);
	}
	close_semaphores(simulation);
	unlink_semaphores();
}
