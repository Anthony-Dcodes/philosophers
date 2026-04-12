/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:59:01 by advorace          #+#    #+#             */
/*   Updated: 2026/04/12 13:09:12 by advorace         ###   ########.fr       */
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
	philosopher->id = i + 1;
	ret = pthread_create(&philosopher->thread, NULL,
			philosopher_loop, philosopher);
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

int	preclean_init_malloc(t_simulation *simulation, pid_t **pids,
						t_philosopher *philosopher)
{
	int	ret;

	ret = ERR_OK;
	init_flags(&simulation->flags);
	unlink_semaphores();
	ret = semaphore_init(simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = pids_malloc(pids, simulation);
	if (ret != ERR_OK)
		return (ret);
	philosopher->sim = simulation;
	return (ret);
}
