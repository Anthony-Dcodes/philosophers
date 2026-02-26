/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/02/25 23:28:57 by advorace         ###   ########.fr       */
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

#define FORK "has taken a fork"
#define LEFT_FORK "has taken a left fork"
#define RIGHT_FORK "has taken a right fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIED "died"

// ERROR CODES
#define ERR_PARSE 1
#define ERR_MEMORY 2
#define ERR_MUTEX 3
#define ERR_THREAD 4

typedef struct s_flags
{
	int	death;
	int	print_mutex_created;
	int	death_mutex_created;
	int	n_threads_created;
	int	n_forks_created;
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

// Init functions
void	init_flags(t_flags *flags);

#endif
