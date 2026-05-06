/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:53:44 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 16:10:40 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"
#include <sys/wait.h> // waitpid

void	monitor_children(pid_t **pids, t_simulation *simulation);
int		spawn_children(t_simulation *simulation,
			t_philosopher *philosopher, pid_t **pids);
void	children_execution(t_philosopher *philosopher,
			t_simulation *simulation, int i, pid_t **pids);
int		reap_pid_terminate_rest(pid_t **pids,
			t_simulation *simulation, int i, int *full_philos);
//void	terminate_children(pid_t **pids, t_simulation *simulation);
void	activate_child_cleanup(t_simulation *sim);
void	*child_destroy_thread(void *arg);
