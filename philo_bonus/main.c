/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/05 17:22:22 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosopher;
	int				ret;
	int				i;
	pid_t			pid;

	i = 0;
	ret = ERR_OK;
	init_flags(&simulation.flags);
	unlink_semaphores();
	printf("Main process id: %d\n", (int)getpid());
	sleep(1);
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = semaphore_init(&simulation);
	if (ret != ERR_OK)
		goto cleanup;
	pid = getpid();
	philosopher->sim = &simulation;
	while (i < simulation.n_philosophers && pid != 0) // spawn all child proceses
	{
		pid = fork();
		printf("new process spawned: %d, returned pidid: %d\n", getpid(), (int)(pid));
		if (pid == 0)
		{
			printf("I am child process! %d\n,", getpid());
			ret = initialize_philosopher_thread(philosopher, i);
			if (ret != ERR_OK)
				goto subprocess_exit;
			
			subprocess_exit:
				subprocess_cleanup(philosopher);
				exit(ERR_OK);

		}
		++i;
	}
	monitoring(&simulation, philosopher);
	log_end_of_simulation(&simulation);
	cleanup:
		unlink_semaphores();
		return (ret);
}
