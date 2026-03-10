#pragma once

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free, exit
# include <string.h> // memset
# include <unistd.h> // write, usleep, fork
# include <sys/time.h> // gettimeofday
# include <limits.h> // INT_MAX
# include <signal.h> // kill
# include <sys/wait.h> // waitpid

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
# include <fcntl.h>

// Philosopher states
#define FORK "has taken a fork"
#define LEFT_FORK "has taken a left fork"
#define RIGHT_FORK "has taken a right fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIED "died"

// ERROR CODES
typedef enum e_error {
    ERR_OK = 0,
    ERR_PARSE,
    ERR_MEMORY,
    ERR_SEMAPHORE,
    ERR_PROCESS
} t_error;

// Semaphore name
#define SEM_FORKS "/sem_forks"
#define SEM_STATE "/sem_state"
#define SEM_PRINT "/sem_print"
#define SEM_MEAL "/sem_meal"

typedef struct s_flags
{
	int	philosopher_died;
	int	n_threads_created;
	int all_philosophers_full;
	int	print_semaphore_created;
	int	state_semaphore_created;
	int fork_semaphore_created;
	int meal_semaphore_created;
} t_flags;

typedef struct s_simulation
{
	int	n_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_must_eat;
	sem_t	*print_semaphore;
	sem_t	*state_semaphore;
	sem_t	*fork_semaphore;
	sem_t	*meal_semaphore;
	t_flags	flags;
} t_simulation;

typedef struct s_philosopher
{
	int	id;
	long	last_meal;
	int		meals_eaten;
	t_simulation	*sim;
} t_philosopher;

int	    perfom_mallocs_initialize_mutexes(t_simulation *simulation, t_philosopher **philosophers);
int	simulation_sem_init(t_simulation *simulation);
void	init_flags(t_flags *flags);
int	parser_args(int argc, char *argv[], t_simulation *simulation);
int	is_int(char *str);
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int	is_more_then_int_max(char *nptr);
int	wrong_number_format(void);
int	not_an_int(void);
int	wrong_number_of_args(void);
