/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:07:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 09:57:25 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include "philosopher.h"
#include "structs.h"
#include "helpers.h"
#include "macros.h"

void	log_general(t_philosopher *philosopher, const char *message)
{
	long	timestamp_ms;
	int		philosopher_n;

	if (get_death(philosopher->sim))
	{
		return ;
	}
	sem_wait(philosopher->sim->print_semaphore);
	philosopher_n = philosopher->id;
	timestamp_ms = get_timestamp_ms();
	printf("%ld %d %s\n", timestamp_ms, philosopher_n, message);
	sem_post(philosopher->sim->print_semaphore);
}

void	log_all_philosophers_ate(t_simulation *sim, int full_philos)
{
	long			timestamp_ms;
	int				ate_n_times;

	if (full_philos != sim->n_philosophers)
		return ;
	ate_n_times = sim->n_times_must_eat;
	sem_wait(sim->print_semaphore);
	timestamp_ms = get_timestamp_ms();
	printf("%ld %s %d %s\n", timestamp_ms, "all philosophers ate",
		ate_n_times, "times");
	sem_post(sim->print_semaphore);
}

void	log_death(t_philosopher *philosopher)
{
	long	current_time_ms;

	current_time_ms = get_timestamp_ms();
	sem_wait(philosopher->sim->death_print_semaphore);
	if (get_timestamp_ms() - current_time_ms >= SLEEP_DELAY)
	{
		sem_post(philosopher->sim->death_print_semaphore);
		return ;
	}
	usleep(SLEEP_DELAY);
	sem_wait(philosopher->sim->print_semaphore);
	printf("%ld %d %s\n", get_timestamp_ms(), philosopher->id, DIED);
	sem_post(philosopher->sim->death_print_semaphore);
	sem_post(philosopher->sim->print_semaphore);
	return ;
}

// void	log_end_of_simulation(t_philosopher *philosopher, int *ret)
// {
// 	int		philosopher_n;
// 	long	timestamp_ms;

// 	if (get_death(philosopher->sim))
// 	{
// 		sem_wait(philosopher->sim->print_semaphore);
// 		philosopher_n = philosopher->id;
// 		timestamp_ms = get_timestamp_ms();
// 		printf("%ld %d %s\n", timestamp_ms, philosopher_n, DIED);
// 		sem_post(philosopher->sim->print_semaphore);
// 		*ret = ERR_DIED;
// 	}
// 	else if (get_philosopher_full(philosopher->sim))
// 		ret = ERR_OK;
// }
