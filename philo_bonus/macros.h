/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:55:53 by codespace         #+#    #+#             */
/*   Updated: 2026/05/06 09:55:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Philosopher states
#define FORK "has taken a fork"
#define LEFT_FORK "has taken a left fork"
#define RIGHT_FORK "has taken a right fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIED "died"

// Semaphore name
#define SEM_FORKS "/sem_forks"
#define SEM_STATE "/sem_state"
#define SEM_PRINT "/sem_print"
#define SEM_MEAL "/sem_meal"
#define SEM_SEATS "/sem_seats"
#define SEM_PHILO_FULL "/sem_philo_full"
#define SEM_DESTROY "/sem_destroy"
#define SEM_DEATH_PRINT "/sem_death_print"

#define SLEEP_DELAY 5000
