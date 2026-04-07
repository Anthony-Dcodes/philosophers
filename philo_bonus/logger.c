/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/04/07 13:49:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	long			timestamp_ms;
	int				philosopher_n;

	if (get_death(philosopher->sim))
		return ;
	else
	{
		sem_wait(philosopher->sim->print_semaphore);
		philosopher_n = philosopher->id;
		timestamp_ms = get_timestamp_ms();
		printf("%ld %d %s\n", timestamp_ms, philosopher_n, message);
		sem_post(philosopher->sim->print_semaphore);
	}
}

void	log_death(t_simulation *sim)
{
	long			timestamp_ms;
	int				philosopher_id;

	philosopher_id = get_death(sim);
	sem_wait(sim->print_semaphore);
	timestamp_ms = get_timestamp_ms();
	printf("%ld %d %s\n", timestamp_ms, philosopher_id, DIED);
	//sem_post(sim->print_semaphore);
}

/*
void	log_all_philosophers_ate(t_simulation *sim)
{
	long			timestamp_ms;
	int				ate_n_times;

	ate_n_times = sim->n_times_must_eat;
	sem_wait(sim->print_semaphore);
	timestamp_ms = get_timestamp_ms();
	printf("%ld %s %d %s\n", timestamp_ms, "all philosophers ate", ate_n_times, "times");
	sem_post(sim->print_semaphore);
}
*/

void	log_end_of_simulation(t_simulation *simulation, int *ret)
{
	if (get_death(simulation))
	{
		log_death(simulation);
		sem_post(simulation->end_simulation_semaphore);
		ret = ERR_DIED;
	}
	else if (get_philosopher_full(simulation))
		ret = ERR_OK;
}
