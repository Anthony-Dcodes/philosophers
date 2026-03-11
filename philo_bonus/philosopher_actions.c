/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:22:34 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 22:11:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	pick_up_forks(t_simulation *simulation)
{
	sem_wait(simulation->fork_semaphore);
	sem_wait(simulation->fork_semaphore);
	return ;
}

static void	put_down_forks(t_simulation *simulation)
{
	sem_post(simulation->fork_semaphore);
	sem_post(simulation->fork_semaphore);
	return ;
}

void	eating(t_philosopher *philosopher)
{
	pick_up_forks(philosopher->sim);
	log_general(philosopher, EAT);
	set_last_meal_time(philosopher);
	usleep(philosopher->sim->time_to_eat * 1000);
	put_down_forks(philosopher->sim);
}

void	sleeping(t_philosopher *philosopher)
{
	log_general(philosopher, SLEEP);
	usleep(philosopher->sim->time_to_sleep * 1000);
}

void	thinking(t_philosopher *philosopher)
{
	log_general(philosopher, THINK);
}

