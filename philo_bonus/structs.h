/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:57:09 by codespace         #+#    #+#             */
/*   Updated: 2026/04/05 17:16:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_flags
{
	int	philosopher_died;
	int all_philosophers_full;
	int	print_semaphore_created;
	int	state_semaphore_created;
	int fork_semaphore_created;
	int meal_semaphore_created;
	int	thread_created;
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
	pthread_t	thread;
} t_philosopher;
