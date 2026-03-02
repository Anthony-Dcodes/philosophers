/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:57:09 by codespace         #+#    #+#             */
/*   Updated: 2026/03/02 08:58:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

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

typedef struct s_flags
{
	int	death;
	int	print_mutex_created;
	int	death_mutex_created;
	int	n_threads_created;
	int	n_forks_created;
	int all_philosophers_full;
} t_flags;

typedef struct s_simulation
{
	int	n_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_must_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_flags	flags;
} t_simulation;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
} t_fork;

typedef struct s_philosopher
{
	int	id;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread;
	t_simulation	*sim;
	long	last_meal;
	int		meals_eaten;
} t_philosopher;

#endif