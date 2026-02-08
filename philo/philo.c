/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/08 10:12:18 by advorace         ###   ########.fr       */
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
	log_pickup_fork(5);
	free(threads);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_simulation	*simul_args;

	simul_args = (t_simulation*)arg;
	log_sleeping(simul_args->n_philosophers);
	return (NULL);
}
