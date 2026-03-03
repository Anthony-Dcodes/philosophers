/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/03/03 16:20:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	clean_up(t_philosopher *philosophers, t_fork *forks, t_simulation *sim)
{
	int	i;

	i = 0;
	if (philosophers)
	{
		while (i < sim->flags.n_threads_created)
			pthread_join(philosophers[i++].thread, NULL);
		free(philosophers);
	}
	i = 0;
	if (forks)
	{
		while (i < sim->flags.n_forks_created)
			pthread_mutex_destroy(&forks[i++].mutex);
		free(forks);
	}
	if (sim->flags.death_mutex_created)
		pthread_mutex_destroy(&sim->death_mutex);
	if (sim->flags.print_mutex_created)
		pthread_mutex_destroy(&sim->print_mutex);
}
