/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/04/09 09:19:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free, exit
# include <string.h> // memset
# include <unistd.h> // write, usleep, fork
# include <sys/time.h> // gettimeofday
# include <limits.h> // INT_MAX
# include <signal.h> // kill
# include <sys/wait.h> // waitpid
# include <fcntl.h> // for O_CREAT

/*
sem_open - initialize and open a named semaphore
sem_close - close a named semaphore
sem_post - increments semaphore by one
sem_wait - decrements semaphore by one
sem_unlink - removes named semaphore, removed immediately, desctoryed once all other processes close it
*/
# include <semaphore.h>
/*
pthread_create - create new thread
pthread_detach - detach a thread (alternative to pthread_join)
pthread_join - wait for a thread to finish
*/
# include <pthread.h>

# include "macros.h"
# include "structs.h"

// Error functions
int	wrong_number_format(void);
int	not_an_int(void);
int	wrong_number_of_args(void);

// Cleanup
void	unlink_semaphores(void);
void	close_semaphores(t_simulation *sim);
void	subprocess_cleanup(t_philosopher *philosopher);

// Parsing
int	parser_args(int argc, char *argv[], t_simulation *t_simulation);
int	is_int(char *str);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int	is_more_then_int_max(char *nptr);

// Logger
void	log_general(t_philosopher *philosopher, const char *message);
void	log_death(t_simulation *sim);
//void	log_all_philosophers_ate(t_simulation *sim);
void	log_end_of_simulation(t_simulation *simulation, int *ret);

// Philosophers main loop / helpers
void	*philosopher_loop(void *arg);
void    handle_single_philosopher(t_philosopher *philosopher);

// Philosophers states
void	eating(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);

// Utils
long	get_timestamp_ms(void);

// Philosphers monitoring
void	death_monitoring(t_philosopher *philosopher, t_simulation *sim);
void	philosopher_full_monitoring(t_philosopher *philosophers, t_simulation *sim);
void    monitoring(t_simulation *simulation, t_philosopher *philosophers);

// Init functions
void	init_flags(t_flags *flags);
int	semaphore_init(t_simulation *simulation);
int	initialize_philosopher_thread(t_philosopher *philosopher, int i);


// Get helpers
int get_death(t_simulation *simulation);
int get_philosopher_full(t_simulation *simulation);
long get_last_meal(t_philosopher *philosopher);
int get_meals_eaten(t_philosopher *philosopher);

// Set helpers
void	set_last_meal_time(t_philosopher *philosopher);
void	set_death(t_simulation *simulation, int id);
void    set_philosopher_full(t_simulation *simulation);
void    set_increment_meals_eaten(t_philosopher *philosopher);

// Monitor children
int    monitor_children(pid_t *pids, t_simulation simulation);
void    terminate_children(pid_t *pids, t_simulation simulation);


