/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 23:09:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	int				ret;
	int				i;
	pid_t			pid;

	i = 0;
	ret = ERR_OK;
	init_flags(&simulation.flags);
	cleanup_semaphores();
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = semaphore_init(&simulation);
	if (ret != ERR_OK)
		goto cleanup;
	while (i < simulation.n_philosophers)
	{
		pid = fork();
		printf("new process spawned: %d, with pid: %d\n", i, (int)(pid));
		++i;
	}
	monitoring(&simulation, philosophers);
	log_end_of_simulation(&simulation);
	cleanup:
		clean_up(&simulation);
		return (ret);
}
