/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/14 14:08:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	t_fork			*forks;
	int				ret;

	ret = ERR_OK;
	init_flags(&simulation.flags);
	if (parser_args(argc, argv, &simulation) != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers, &forks);
	if (ret != ERR_OK)
	{
		clean_up(philosophers, forks, &simulation);
		return (ret);
	}
	ret = initialize_philosophers_threads(philosophers, &simulation, forks);
	if (ret != ERR_OK)
	{
		clean_up(philosophers, forks, &simulation);
		return (ret);
	}
	monitoring(&simulation, philosophers);
	log_end_of_simulation(&simulation);
	clean_up(philosophers, forks, &simulation);
	return (ret);
}
