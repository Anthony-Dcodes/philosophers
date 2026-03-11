/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 21:23:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	cleanup_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
}

void	clean_up(t_philosopher *philosophers, t_fork *forks, t_simulation *sim)
{
	int	i;

	i = 0;
	if (philosophers)
	{
		while (i < sim->flags.n_meal_mutex_created)
			pthread_mutex_destroy(&philosophers[i++].meal_mutex);
		i = 0;
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
	if (sim->flags.state_mutex_created)
		pthread_mutex_destroy(&sim->state_mutex);
	if (sim->flags.print_mutex_created)
		pthread_mutex_destroy(&sim->print_mutex);
}
