/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:58:04 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 12:59:01 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"
#include <sys/wait.h>

// Cleanup
void	unlink_semaphores(void);
void	close_semaphores(t_simulation *sim);
void	subprocess_cleanup(t_philosopher *philosopher, pid_t *pids);
void	free_memory(pid_t *pids);
void	main_process_cleanup(pid_t *pids, t_simulation *simulation);
