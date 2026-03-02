/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/03/02 11:53:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <unistd.h> // write, usleep,
# include <sys/time.h> // gettimeofday
# include <limits.h> // INT_MAX

# include "philo_macros.h"
# include "philo_structs.h"

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

// Logs
void	log_general(t_philosopher *philosopher, const char *message);
void	log_death(t_simulation *sim);
void	log_all_philosophers_ate(t_simulation *sim);

// Philosophers main loop / helpers
void	*philo_loop(void *arg);

// Mutex
int	simulation_mutex_init(t_simulation *simulation);
int	fork_mutex_init(t_fork *fork);

// Philosophers states
void	eating(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);

// Utils
long	get_timestamp_ms(void);
void	set_last_meal_time(t_philosopher *philosopher);

// Philosphers monitoring
void	death_monitoring(t_philosopher *philosophers, t_simulation *sim);
void	philosophers_full_monitoring(t_philosopher *philosophers, t_simulation *sim);

// Init functions
void	init_flags(t_flags *flags);

#endif
