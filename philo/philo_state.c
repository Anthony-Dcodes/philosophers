/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:22:34 by advorace          #+#    #+#             */
/*   Updated: 2026/03/02 13:04:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pick_up_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, LEFT_FORK);
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		log_general(philosopher, RIGHT_FORK);
	}
	else
	{
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		log_general(philosopher, RIGHT_FORK);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, LEFT_FORK);
	}
	return ;
}

static void	put_down_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	return ;
}

void	eating(t_philosopher *philosopher)
{
	pick_up_forks(philosopher);
	log_general(philosopher, EAT);
	set_last_meal_time(philosopher);
	usleep(philosopher->sim->time_to_eat * 1000);
	put_down_forks(philosopher);
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

