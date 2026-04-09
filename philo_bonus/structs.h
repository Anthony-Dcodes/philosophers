/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:57:09 by codespace         #+#    #+#             */
/*   Updated: 2026/04/09 11:38:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_flags
{
	int	philosopher_died;
	int philosopher_full;
	int	thread_created;
	int	pids_mallocked;
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
	sem_t	*end_simulation_semaphore;
	sem_t	*seats_semaphore;
	t_flags	flags;
} t_simulation;

typedef struct s_philosopher
{
	int	id;
	long	last_meal;
	int		meals_eaten;
	t_simulation	*sim;
	pthread_t	thread;
} t_philosopher;
