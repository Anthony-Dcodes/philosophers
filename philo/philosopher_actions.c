/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:22:34 by advorace          #+#    #+#             */
/*   Updated: 2026/04/25 22:18:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	pick_up_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, FORK);
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		log_general(philosopher, FORK);
	}
	else
	{
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		log_general(philosopher, FORK);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, FORK);
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
	long	think_time;
	int		t_eat;
	int		t_die;

	t_eat = philosopher->sim->time_to_eat;
	t_die = philosopher->sim->time_to_die;
	think_time = (t_die
			- (get_timestamp_ms() - get_last_meal(philosopher))
			- t_eat) / 2;
	log_general(philosopher, THINK);
	if (think_time > 0)
		usleep(think_time * 1000);
}
