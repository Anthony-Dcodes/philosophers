/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/03/07 10:43:49 by advorace         ###   ########.fr       */
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
	ret = parser_args(argc, argv, &simulation);
	printf("parsing_done\n");
	if (ret != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers, &forks);
	printf("mallocs and mutex init done\n");
	if (ret != ERR_OK)
		goto cleanup;
	ret = initialize_philosophers_threads(philosophers, &simulation, forks);
	printf("threads running\n");
	if (ret != ERR_OK)
		goto cleanup;
	monitoring(&simulation, philosophers);
	log_end_of_simulation(&simulation);
	cleanup:
		clean_up(philosophers, forks, &simulation);
		return (ret);
}
