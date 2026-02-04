/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/02/04 22:30:42 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_pickup_fork(int philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d has taken a fork\n", timestamp_ms, philosopher);
}

void	log_eating(int philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d is eating\n", timestamp_ms, philosopher);
}

void	log_sleeping(int philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d is sleeping\n", timestamp_ms, philosopher);
}

void	log_thinking(int philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d is thinking\n", timestamp_ms, philosopher);
}

void	log_death(int philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	printf("%ld %d died\n", timestamp_ms, philosopher);
}
