/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:59:01 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 13:52:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "structs.h"
#include "error.h"
#include "cleanup.h"
#include "init.h"

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
