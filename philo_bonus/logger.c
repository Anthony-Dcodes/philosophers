/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/04/11 20:06:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	long	timestamp_ms;
	int		philosopher_n;

	sem_wait(philosopher->sim->end_simulation_semaphore);
	if (get_death(philosopher->sim))
	{
		sem_post(philosopher->sim->end_simulation_semaphore);
		return ;
	}
	sem_wait(philosopher->sim->print_semaphore);
	philosopher_n = philosopher->id;
	timestamp_ms = get_timestamp_ms();
	printf("%ld %d %s\n", timestamp_ms, philosopher_n, message);
	sem_post(philosopher->sim->print_semaphore);
	sem_post(philosopher->sim->end_simulation_semaphore);
}

void	log_all_philosophers_ate(t_simulation *sim)
{
	long			timestamp_ms;
	int				ate_n_times;

	ate_n_times = sim->n_times_must_eat;
	sem_wait(sim->print_semaphore);
	timestamp_ms = get_timestamp_ms();
	printf("%ld %s %d %s\n", timestamp_ms, "all philosophers ate",
		ate_n_times, "times");
	sem_post(sim->print_semaphore);
}

void	log_end_of_simulation(t_philosopher *philosopher, int *ret)
{
	int		philosopher_n;
	long	timestamp_ms;

	if (get_death(philosopher->sim))
	{
		sem_wait(philosopher->sim->end_simulation_semaphore);
		sem_wait(philosopher->sim->print_semaphore);
		philosopher_n = philosopher->id;
		timestamp_ms = get_timestamp_ms();
		printf("%ld %d %s\n", timestamp_ms, philosopher_n, DIED);
		sem_post(philosopher->sim->print_semaphore);
		*ret = ERR_DIED;
	}
	else if (get_philosopher_full(philosopher->sim))
		ret = ERR_OK;
}
