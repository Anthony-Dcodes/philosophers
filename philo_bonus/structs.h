/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:57:09 by codespace         #+#    #+#             */
/*   Updated: 2026/05/06 07:43:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <semaphore.h>
#include <pthread.h>

typedef struct s_flags
{
	int	philosopher_died;
	int	philosopher_full;
	int	thread_created;
	int	pids_mallocked;
	int	philo_full_thread_created;
	int	destroy_thread_created;
}	t_flags;

typedef struct s_simulation
{
	int		n_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_times_must_eat;
	sem_t	*print_semaphore;
	sem_t	*state_semaphore;
	sem_t	*fork_semaphore;
	sem_t	*meal_semaphore;
	sem_t	*seats_semaphore;
	sem_t	*philo_full_semaphore;
	sem_t	*destroy_semaphore;
	sem_t	*death_print_semaphore;
	t_flags	flags;
}	t_simulation;

typedef struct s_philosopher
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	t_simulation	*sim;
	pthread_t		thread;
	pthread_t		philo_full_thread;
	pthread_t		destroy_thread;
}	t_philosopher;
