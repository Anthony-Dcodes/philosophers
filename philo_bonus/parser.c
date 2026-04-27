/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:55:13 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 14:14:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "error.h"

// If success - 0, else 1
int	parser_args(int argc, char *argv[], t_simulation *simulation)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		wrong_number_of_args();
		return (ERR_PARSE);
	}
	while (argv[i])
	{
		if (!is_int(argv[i]))
			return (ERR_PARSE);
		++i;
	}
	simulation->n_philosophers = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->n_times_must_eat = ft_atoi(argv[5]);
	else
		memset(&simulation->n_times_must_eat, 0, sizeof(int));
	return (0);
}
