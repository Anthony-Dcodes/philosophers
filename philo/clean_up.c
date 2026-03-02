/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/03/02 13:04:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_philosopher *philosophers, t_fork *forks, t_simulation *sim)
{
	int	i;

	i = 0;
	printf("Cleaninging up\n");
	if (philosophers)
	{
		while (i < sim->flags.n_threads_created)
		{
			pthread_join(philosophers[i].thread, NULL);
			++i;
		}
		free(philosophers);
	}
	i = 0;
	if (forks)
	{
		while (i < sim->flags.n_forks_created)
		{
			pthread_mutex_destroy(&forks[i].mutex);
			++i;
		}
		free(forks);
	}
	if (sim->flags.death_mutex_created)
		pthread_mutex_destroy(&sim->death_mutex);
	if (sim->flags.print_mutex_created)
		pthread_mutex_destroy(&sim->print_mutex);
}
