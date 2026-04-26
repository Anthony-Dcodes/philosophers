/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:09:43 by codespace         #+#    #+#             */
/*   Updated: 2026/04/26 12:44:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	monitor_children(pid_t **pids, t_simulation *simulation)
{
	int	i;
	int	full_philos;

	i = 0;
	full_philos = 0;
	while (full_philos != simulation->n_philosophers)
	{
		if (i == simulation->n_philosophers)
			i = 0;
		if ((*pids)[i] == 0)
		{
			++i;
			continue ;
		}
		if (reap_pid_terminate_rest(pids, simulation, i, &full_philos))
			return ;
		++i;
	}
	log_all_philosophers_ate(simulation, full_philos);
}

