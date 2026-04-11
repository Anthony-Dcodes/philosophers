/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/11 20:10:38 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	philosopher;
	int				ret;
	int				full_philos;
	pid_t			*pids;

	ret = ERR_OK;
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		goto cleanup;
	ret = preclean_init_malloc(&simulation, &pids, &philosopher);
	if (ret != ERR_OK)
		goto cleanup;
	ret = spawn_children(&simulation, &philosopher, &pids);
	if (ret != ERR_OK)
		goto cleanup;
	monitor_children(&pids, &simulation);
	cleanup:
		terminate_children(&pids, &simulation);
		free_memory(pids);
		close_semaphores(&simulation);
		unlink_semaphores();
		return (ret);
}
