/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:09:43 by codespace         #+#    #+#             */
/*   Updated: 2026/04/11 20:39:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	monitor_children(pid_t **pids, t_simulation *simulation)
{
	int	i;
	int	status;
	int	full_philos;

	i = 0;
	full_philos = 0;
	while (full_philos != simulation->n_philosophers)
	{
		if (i == simulation->n_philosophers)
			i = 0;
		if (waitpid((*pids)[i], &status, WNOHANG) > 0)
		{
			(*pids)[i] = 0;
			if (WIFEXITED(status) && WEXITSTATUS(status) > 0)
			{
				terminate_children(pids, simulation);
				return ;
			}
			else
				++full_philos;
		}
		++i;
	}
	if (full_philos == simulation->n_philosophers)
		log_all_philosophers_ate(simulation);
}
