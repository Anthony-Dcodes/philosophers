/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/03/08 16:43:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <unistd.h> // write, usleep,
# include <sys/time.h> // gettimeofday
# include <limits.h> // INT_MAX

# include "macros.h"
# include "structs.h"

// Error functions
int	wrong_number_format(void);
int	not_an_int(void);
int	wrong_number_of_args(void);
void	clean_up(t_philosopher *philosophers, t_fork *forks, t_simulation *sim);

// Parsing
int	parser_args(int argc, char *argv[], t_simulation *t_simulation);
int	is_int(char *str);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int	is_more_then_int_max(char *nptr);

// Logger
void	log_general(t_philosopher *philosopher, const char *message);
void	log_death(t_simulation *sim);
void	log_all_philosophers_ate(t_simulation *sim);
void	log_end_of_simulation(t_simulation *simulation);

// Philosophers main loop / helpers
void	*philosopher_loop(void *arg);
void    handle_single_philosopher(t_philosopher *philosopher);

// Mutex
int	simulation_mutex_init(t_simulation *simulation);
int	fork_mutex_init(t_fork *fork);
int	meal_mutex_init(t_philosopher *philosopher);

// Philosophers states
void	eating(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);

// Utils
long	get_timestamp_ms(void);

// Philosphers monitoring
void	death_monitoring(t_philosopher *philosophers, t_simulation *sim);
void	philosophers_full_monitoring(t_philosopher *philosophers, t_simulation *sim);
void    monitoring(t_simulation *simulation, t_philosopher *philosophers);

// Init functions
void	init_flags(t_flags *flags);
int     initialize_philosophers_threads(t_philosopher *philosophers, t_simulation *simulation, t_fork *forks);
int	    perfom_mallocs_initialize_mutexes(t_simulation *simulation, t_philosopher **philosophers, t_fork **forks);
int     initialize_mutexes(t_simulation *simulation, t_philosopher **philosophers, t_fork **forks, int i);

// Get helpers
int get_death(t_simulation *simulation);
int get_all_philosophers_full(t_simulation *simulation);
long get_last_meal(t_philosopher *philosopher);
int get_meals_eaten(t_philosopher *philosopher);

// Set helpers
void	set_last_meal_time(t_philosopher *philosopher);
void	set_death(t_simulation *simulation, int id);
void    set_all_philosophers_full(t_simulation *simulation);
void    set_increment_meals_eaten(t_philosopher *philosopher);
