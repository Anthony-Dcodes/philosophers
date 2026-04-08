/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/08 14:51:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosopher;
	int				ret;
	int				i;
	int				j;
	int				status;
	int				full_philos;
	pid_t			pid;
	pid_t			*pids;

	i = 0;
	ret = ERR_OK;
	init_flags(&simulation.flags);
	unlink_semaphores();
	printf("Main process id: %d\n", (int)getpid());
	//sleep(1);
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
	philosopher = malloc(sizeof(t_philosopher));
	if (!philosopher)
	{
		ret = ERR_MEMORY;
		goto cleanup;
	}
	printf("pids allocated\n");
	pid = getpid();
	philosopher->sim = &simulation;
	printf("before while loop\n");
	while (i < simulation.n_philosophers && pid != 0) // spawn all child proceses
	{
		pid = fork();
		printf("new process spawned: %d, returned pidid: %d\n", getpid(), (int)(pid));
		if (pid < 0)
		{
			//fork failed
			ret = ERR_FORK;
			goto cleanup;
		}
		else if (pid == 0)
		{
			sleep(2);
			printf("I am child process! %d\n", getpid());
			ret = initialize_philosopher_thread(philosopher, i);
			if (ret != ERR_OK)
				exit(ret);
			//sleep(10);
			monitoring(&simulation, philosopher);
			log_end_of_simulation(&simulation, &ret);
			exit(ret);
			//subprocess_exit:
			//	subprocess_cleanup(philosopher);
			//	exit(ret);

		}
		else
			pids[i] = pid;
		++i;
	}
	i = 0;
	j = 0;
	full_philos = 0;
	while (i < simulation.n_philosophers && full_philos != simulation.n_philosophers)
	{
		if (waitpid(pids[i], &status, WNOHANG) > 0)
		{
			pids[i] = 0;
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) > 0)
				{
					while (pids[j])
					{
						printf("killing all processes from main proces\n");
						kill(pids[j], SIGKILL);
						waitpid(pids[j], &status, 0);
						++j;
					}
					break;
				}
				else
					++full_philos;
			}
		}
		if (i == simulation.n_philosophers - 1)
			i = 0;
		else
			++i;
	}
	if (full_philos == simulation.n_philosophers)
		printf("All philosophers are full!\n");
	//monitoring(&simulation, philosopher);
	//log_end_of_simulation(&simulation);
	cleanup:
		unlink_semaphores();
		return (ret);
}
