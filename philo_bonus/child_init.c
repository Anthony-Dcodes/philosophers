/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:43:03 by codespace         #+#    #+#             */
/*   Updated: 2026/04/26 12:46:39 by advorace         ###   ########.fr       */
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
