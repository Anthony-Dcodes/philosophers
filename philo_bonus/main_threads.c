/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 07:34:37 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 08:30:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "structs.h"
#include "error.h"
#include "child.h"
#include "main_threads.h"

int	init_philo_full_thread(t_philosopher *philosopher)
{
	int	ret;

	ret = pthread_create(&philosopher->philo_full_thread, NULL, philo_full_thread, philosopher);
	if (ret != ERR_OK)
		return (ERR_THREAD);
	philosopher->sim->flags.philo_full_thread_created = 1;
	return (ret);
}

void	*philo_full_thread(void	*arg)
{
	t_philosopher	*philosopher;
	int				i;

	philosopher = (t_philosopher *)arg;
	i = 0;
	while (i < philosopher->sim->n_philosophers)
	{
		sem_wait(philosopher->sim->philo_full_semaphore);
		++i;
	}
	activate_child_cleanup(philosopher->sim);
}

void	terminate_philo_full_thread(t_philosopher *philosopher)
{
	int				i;
	t_simulation	*sim;

	i = 0;
	sim = philosopher->sim;
	if (sim->flags.philo_full_thread_created)
	{
		while (i < sim->n_philosophers)
		{
			sem_post(sim->philo_full_semaphore);
			++i;
		}
		pthread_detach(philosopher->philo_full_thread);
	}
}
