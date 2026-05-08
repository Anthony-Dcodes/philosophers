/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:43:03 by codespace         #+#    #+#             */
/*   Updated: 2026/05/08 17:44:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child.h"
#include "error.h"
#include <unistd.h>
#include "main_threads.h"

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
	ret = init_philo_full_thread(philosopher);
	return (ERR_OK);
}
