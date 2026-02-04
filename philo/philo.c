/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/02/04 18:46:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation simulation;

	if (parser_args(argc, argv, &simulation))
		return (1);
	printf("Number of philo: %d\n", simulation.n_philosophers);
	printf("Time to die: %d\n", simulation.time_to_die);
	printf("Time to eat: %d\n", simulation.time_to_eat);
	printf("Time to sleep: %d\n", simulation.time_to_sleep);
}
