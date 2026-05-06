/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:12:51 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 16:11:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "cleanup.h"
#include "structs.h"
#include "child.h"
#include "main_threads.h"

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

void	main_process_cleanup(pid_t *pids, t_philosopher *philosopher)
{
	t_simulation *sim;

	sim = philosopher->sim;
	if (sim->flags.pids_mallocked)
	{
		//terminate_children(&pids, sim);
		free_memory(pids);
	}
	terminate_philo_full_thread(philosopher);
	close_semaphores(sim);
	unlink_semaphores();
}
