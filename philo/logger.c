/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/03/04 16:31:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	long			timestamp_ms;
	int				philosopher_n;

	pthread_mutex_lock(&philosopher->sim->state_mutex);
	if (get_death(&philosopher->sim))
	{
		pthread_mutex_unlock(&philosopher->sim->state_mutex);
		return ;
	}
	else
	{
		pthread_mutex_unlock(&philosopher->sim->state_mutex);
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

	philosopher_id = get_death(sim);
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

void	log_end_of_simulation(t_simulation *simulation)
{
	if (get_death(simulation))
		log_death(simulation);
	else if (get_all_philosophers_full(simulation))
		log_all_philosophers_ate(simulation);
}
