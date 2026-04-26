/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:46:43 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 12:46:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	close_semaphores(philosopher->sim);
	free(*pids);
	exit(ret);
}
