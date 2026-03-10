/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:57:09 by codespace         #+#    #+#             */
/*   Updated: 2026/03/10 21:16:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_flags
{
	int	philosopher_died;
	int	print_semaphore_created;
	int	state_semaphore_created;
	int	n_threads_created;
	int	n_forks_created;
	int all_philosophers_full;
	int	n_meal_mutex_created;
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
	t_flags	flags;
} t_simulation;

typedef struct s_fork
{
	sem_t	*fork_semaphore;
} t_fork;

typedef struct s_philosopher
{
	int	id;
	t_simulation	*sim;
	long	last_meal;
	int		meals_eaten;
	sem_t	*meal_semaphore;
} t_philosopher;
