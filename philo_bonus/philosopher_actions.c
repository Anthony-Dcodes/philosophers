/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:22:34 by advorace          #+#    #+#             */
/*   Updated: 2026/04/08 15:47:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	pick_up_forks(t_philosopher *philosopher)
{
	sem_wait(philosopher->sim->seats_semaphore);
	sem_wait(philosopher->sim->fork_semaphore);
	log_general(philosopher, FORK);
	sem_wait(philosopher->sim->fork_semaphore);
	log_general(philosopher, FORK);
	sem_post(philosopher->sim->seats_semaphore);
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
	pick_up_forks(philosopher);
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

