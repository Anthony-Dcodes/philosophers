/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/08 09:53:18 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	int				i;
	pthread_t		thread;

	i = 1;
	if (parser_args(argc, argv, &simulation))
		return (1);
	printf("Parser done\n");
	while (i <= simulation.n_philosophers)
	{
		pthread_create(&thread, NULL, philo_loop, &simulation);
		++i;
	}
	log_pickup_fork(5);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_simulation	*simul_args;

	simul_args = (t_simulation*)arg;
	log_sleeping(simul_args->n_philosophers);
	return (NULL);
}
