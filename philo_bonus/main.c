/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:23:55 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 13:38:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "parser.h"
#include "cleanup.h"
#include "child.h"
#include "init.h"

int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	philosopher;
	int				ret;
	int				full_philos;
	pid_t			*pids;

	ret = ERR_OK;
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = preclean_init_malloc(&simulation, &pids, &philosopher);
	if (ret != ERR_OK)
	{
		main_process_cleanup(pids, &simulation);
		return (ret);
	}
	ret = spawn_children(&simulation, &philosopher, &pids);
	if (ret != ERR_OK)
	{
		main_process_cleanup(pids, &simulation);
		return (ret);
	}
	monitor_children(&pids, &simulation);
	main_process_cleanup(pids, &simulation);
	return (ret);
}
