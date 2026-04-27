/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 14:00:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Logger
void	log_general(t_philosopher *philosopher, const char *message);
//void	log_death(t_simulation *sim);
void	log_all_philosophers_ate(t_simulation *sim, int full_philos);
//void	log_end_of_simulation(t_philosopher *philosopher, int *ret);

// Philosophers main loop / helpers
int		initialize_philosopher_thread(t_philosopher *philosopher, int i);
void	*philosopher_loop(void *arg);
void	handle_single_philosopher(t_philosopher *philosopher);
void	think_eat_sleep(t_philosopher *philosopher);

// Philosophers actions
void	eating(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);

// Utils
long	get_timestamp_ms(void);

// Philosphers monitoring
void	death_monitoring(t_philosopher *philosopher, t_simulation *sim);
void	philosopher_full_monitoring(t_philosopher *philosophers,
			t_simulation *sim);
void	monitoring(t_simulation *simulation, t_philosopher *philosophers);

