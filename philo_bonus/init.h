/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:01:47 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 13:17:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"
#include <sys/wait.h>

// Init functions
void	init_flags(t_flags *flags);
int		semaphore_init(t_simulation *simulation);
int		pids_malloc(pid_t **pids, t_simulation *simulation);
int		preclean_init_malloc(t_simulation *simulation, pid_t **pids,
			t_philosopher *philosopher);
