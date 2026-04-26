/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:34:50 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 12:34:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_single_philosopher(t_philosopher *philosopher)
{
	thinking(philosopher);
	sem_wait(philosopher->sim->fork_semaphore);
	log_general(philosopher, FORK);
	usleep(philosopher->sim->time_to_die * 1000);
	sem_post(philosopher->sim->fork_semaphore);
}

void	think_eat_sleep(t_philosopher *philosopher)
{
	thinking(philosopher);
	eating(philosopher);
	sleeping(philosopher);
}
