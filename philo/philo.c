/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/09 19:36:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	int				i;
	pthread_t		*threads;

	i = 0;
	if (parser_args(argc, argv, &simulation))
		return (1);
	printf("Parser done\n");
	if (mutex_init(&simulation))
		return (1);
	threads = malloc(sizeof(pthread_t) * simulation.n_philosophers);
	if (!threads)
		return (1);
	while (i < simulation.n_philosophers)
	{
		pthread_create(&threads[i], NULL, philo_loop, &simulation);
		++i;
	}
	i = 0;
	while (i < simulation.n_philosophers)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	free(threads);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_simulation	*simulation;

	simulation = (t_simulation*)arg;
	usleep(simulation->time_to_sleep);
	log_general(simulation, EAT);
	log_general(simulation, SLEEP);
	log_general(simulation, THINK);
	log_general(simulation, DIED);
	log_general(simulation, FORK);
	return (NULL);
}
