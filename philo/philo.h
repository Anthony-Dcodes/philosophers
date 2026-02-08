/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/02/08 09:43:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <unistd.h> // write, usleep,
# include <sys/time.h> // gettimeofday
# include <limits.h>

/*
pthread_create - create new thread
pthread_detach - detach a thread (alternative to pthread_join)
pthread_join - wait for a thread to finish
pthread_mutex_init - initialize mutex (lock, each fork will be a mutex)
pthread_mutex_destroy - destroy / cleanup a mutex
pthread_mutex_lock - lock a mutex (acquire the fork, block if already locked by another thread)
pthread_mutex_unlock - unlock a mutex (release the fork), allows other threads to acquire it
*/
# include <pthread.h>

typedef struct s_simulation
{
	int	n_philosophers;
	int	n_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_must_eat;
} t_simulation;

// Error functions
int	wrong_number_format(void);
int	not_an_int(void);
int	wrong_number_of_args(void);

// Parsing
int	parser_args(int argc, char *argv[], t_simulation *t_simulation);
int	is_int(char *str);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int	is_more_then_int_max(char *nptr);

// Logs
void	log_pickup_fork(int philosopher);
void	log_eating(int philosopher);
void	log_sleeping(int philosopher);
void	log_thinking(int philosopher);
void	log_death(int philosopher);

// Philosophers main loop / helpers
void	*philo_loop(void *arg);

#endif
