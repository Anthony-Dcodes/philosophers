/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/03/10 23:21:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	int				ret;

	ret = ERR_OK;
	init_flags(&simulation.flags);
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers, &forks);
	if (ret != ERR_OK)
		goto cleanup;
	ret = initialize_philosophers_threads(philosophers, &simulation, forks);
	if (ret != ERR_OK)
		goto cleanup;
	monitoring(&simulation, philosophers);
	log_end_of_simulation(&simulation);
	cleanup:
		clean_up(philosophers, forks, &simulation);
		return (ret);
}
