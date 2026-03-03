/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/03/03 15:59:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	t_fork			*forks;
	int				ret;

	ret = ERR_OK;
	init_flags(&simulation.flags);
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers, &forks);
	if (ret != ERR_OK)
		goto cleanup;
	ret = initialize_philosophers_threads(philosophers, &simulation, forks);
	if (ret != ERR_OK)
		goto cleanup;
	monitoring(&simulation, philosophers);
	log_end_of_simulation(&simulation);
	cleanup:
		clean_up(philosophers, forks, &simulation);
		return (ret);
}

void	*philo_loop(void *arg)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = (t_philosopher*)arg;
	set_last_meal_time(philosopher);
	if (philosopher->sim->n_philosophers == 1)
	{
		thinking(philosopher);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		log_general(philosopher, FORK);
		usleep(philosopher->sim->time_to_die * 1000);
		pthread_mutex_unlock(&philosopher->left_fork->mutex);
		return (NULL);
	}
	else if (philosopher->sim->n_times_must_eat)
		while (i < philosopher->sim->n_times_must_eat && !philosopher->sim->flags.death)
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
			++philosopher->meals_eaten;
			++i;
		}
	else
		while (!philosopher->sim->flags.death)
		{
			thinking(philosopher);
			eating(philosopher);
			sleeping(philosopher);
		}
	return (NULL);
}
