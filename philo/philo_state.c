/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:22:34 by advorace          #+#    #+#             */
/*   Updated: 2026/02/12 20:33:33 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void static	pick_up_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		pthread_mutex_lock(&philosopher->right_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
	}
	return ;
}

void static	put_down_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	return ;
}

void	eating(t_philosopher *philosopher)
{
	pick_up_forks(philosopher);
	log_general(philosopher, EAT);
	usleep(philosopher->sim->time_to_eat * 1000);
	set_last_meal_time(philosopher);
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

