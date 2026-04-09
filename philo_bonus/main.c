/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/09 11:52:46 by codespace        ###   ########.fr       */
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
	init_flags(&simulation.flags);
	unlink_semaphores();
	printf("Main process id: %d\n", (int)getpid());
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = semaphore_init(&simulation);
	if (ret != ERR_OK)
		goto cleanup;
	printf("semaphores done\n");
	pids = malloc(sizeof(pid_t) * simulation.n_philosophers);
	if (!pids)
	{
		ret = ERR_MEMORY;
		goto cleanup;
	}
	simulation.flags.pids_mallocked = 1;
	printf("pids allocated\n");
	philosopher.sim = &simulation;
	printf("before while loop\n");
	ret = spawn_children(simulation, philosopher, pids);
	full_philos = monitor_children(pids, simulation);
	if (full_philos == simulation.n_philosophers)
		printf("All philosophers are full!\n");
	cleanup:
		terminate_children(pids, simulation);
		free_memory(pids);
		close_semaphores(&simulation);
		unlink_semaphores();
		return (ret);
}
