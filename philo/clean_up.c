/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/02/17 22:10:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_up(t_philosopher *philosophers, t_fork *forks, t_simulation *sim)
{
	int	i;

	i = 0;
	printf("Cleaninging up\n");
	while (i < sim->n_threads_created)
	{
		pthread_join(philosophers[i].thread, NULL);
		++i;
	}
	i = 0;
	if (forks)
	{
		while (i < sim->n_forks_created)
		{
			pthread_mutex_destroy(&forks[i].mutex);
			++i;
		}
		free(forks);
	}
	pthread_mutex_destroy(&sim->death_mutex);
	pthread_mutex_destroy(&sim->print_mutex);
	free(philosophers);
	return (1);
}
