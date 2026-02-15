/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/02/15 23:07:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	struct timeval	tp;
	long			timestamp_ms;
	int				philosopher_n;

	pthread_mutex_lock(&philosopher->sim->death_mutex);
	if (philosopher->sim->death)
	{
		pthread_mutex_unlock(&philosopher->sim->death_mutex);
		return ;
	}
	else
	{
		pthread_mutex_unlock(&philosopher->sim->death_mutex);
		pthread_mutex_lock(&philosopher->sim->print_mutex);
		philosopher_n = philosopher->id;
		gettimeofday(&tp, NULL);
		timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		printf("%ld %d %s\n", timestamp_ms, philosopher_n, message);
		pthread_mutex_unlock(&philosopher->sim->print_mutex);
	}
}

void	log_death(int philosopher_id)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d %s\n", timestamp_ms, philosopher_id, DIED);
}
