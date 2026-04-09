/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:59:01 by advorace          #+#    #+#             */
/*   Updated: 2026/04/09 14:05:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_flags(t_flags *flags)
{
	memset(flags, 0, sizeof(t_flags));
}

int	initialize_philosopher_thread(t_philosopher *philosopher, int i)
{
	int	ret;

	ret = ERR_OK;
	//printf("set philo id to: %d\n", i + 1);
	philosopher->id = i + 1;
	philosopher->meals_eaten = 0;
	ret = pthread_create(&philosopher->thread, NULL, philosopher_loop, philosopher);
	if (ret != ERR_OK)
	{
		ret = ERR_THREAD;
		return (ret);
	}
	philosopher->sim->flags.thread_created = 1;
	return (ret);
}

int	pids_malloc(pid_t **pids, t_simulation *simulation)
{
	*pids = malloc(sizeof(pid_t) * simulation->n_philosophers);
	if (!*pids)
		return (ERR_MEMORY);
	simulation->flags.pids_mallocked = 1;
	return (ERR_OK);
}

int	preclean_init_malloc(t_simulation *simulation, pid_t **pids, t_philosopher *philosopher)
{
	int	ret;
	
	ret = ERR_OK;
	init_flags(&simulation->flags);
	unlink_semaphores();
	printf("Main process id: %d\n", (int)getpid());
	ret = semaphore_init(simulation);
	if (ret != ERR_OK)
		return (ret);
	printf("semaphores done\n");
	ret = pids_malloc(pids, simulation);
	if (ret != ERR_OK)
		return (ret);
	printf("pids allocated\n");
	philosopher->sim = simulation;
	return (ret);
}
