/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:46:43 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 09:40:48 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "structs.h"
#include "error.h"
#include "helpers.h"
#include "cleanup.h"
#include "philosopher.h"

void	children_execution(t_philosopher *philosopher,
						t_simulation *simulation, int i, pid_t **pids)
{
	int	ret;

	ret = ERR_OK;
	set_last_meal_time(philosopher);
	philosopher->meals_eaten = 0;
	ret = initialize_philosopher_thread(philosopher, i);
	if (ret == ERR_OK)
		monitoring(simulation, philosopher);
	if (get_death(simulation))
		ret = ERR_DIED;
	if (philosopher->sim->flags.thread_created && get_death(simulation) == 0)
	{
		pthread_join(philosopher->thread, NULL);
	}
	if (philosopher->sim->flags.destroy_thread_created)
		pthread_detach(philosopher->destroy_thread);
	close_semaphores(philosopher->sim);
	free(*pids);
	exit(ret);
}
