/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/02/16 18:53:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	long			timestamp_ms;
	int				philosopher_n;

	pthread_mutex_lock(&philosopher->sim->death_mutex);
	if (philosopher->sim->flags.death)
	{
		pthread_mutex_unlock(&philosopher->sim->death_mutex);
		return ;
	}
	else
	{
		pthread_mutex_unlock(&philosopher->sim->death_mutex);
		pthread_mutex_lock(&philosopher->sim->print_mutex);
		philosopher_n = philosopher->id;
		timestamp_ms = get_timestamp_ms();
		printf("%ld %d %s\n", timestamp_ms, philosopher_n, message);
		pthread_mutex_unlock(&philosopher->sim->print_mutex);
	}
}

void	log_death(t_simulation *sim)
{
	long			timestamp_ms;
	int				philosopher_id;

	philosopher_id = sim->flags.death;
	pthread_mutex_lock(&sim->print_mutex);	
	timestamp_ms = get_timestamp_ms();
	printf("%ld %d %s\n", timestamp_ms, philosopher_id, DIED);
	pthread_mutex_unlock(&sim->print_mutex);
}

void	log_all_philosophers_ate(t_simulation *sim)
{
	long			timestamp_ms;
	int				ate_n_times;

	ate_n_times = sim->n_times_must_eat;
	pthread_mutex_lock(&sim->print_mutex);
	timestamp_ms = get_timestamp_ms();
	printf("%ld %s %d %s\n", timestamp_ms, "all philosophers ate", ate_n_times, "times");
	pthread_mutex_unlock(&sim->print_mutex);
}
