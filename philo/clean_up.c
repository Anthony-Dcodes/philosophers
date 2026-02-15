/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/02/15 23:13:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_up(t_philosopher *philosophers, t_fork *forks)
{
	int	i;
	int	count;

	i = 0;
	count = philosophers->sim->n_philosophers;
	printf("Cleaninging up\n");
	while (i < count)
	{
		pthread_join(philosophers[i].thread, NULL);
		pthread_mutex_destroy(&forks[i].mutex);
		pthread_mutex_destroy(&philosophers[i].sim->death_mutex);
		pthread_mutex_destroy(&philosophers[i].sim->print_mutex);
		++i;
		printf("Clean up philosopher: %d\n", i);
	}
	free(forks);
	free(philosophers);
	return (1);
}
