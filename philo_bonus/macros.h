/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:55:53 by codespace         #+#    #+#             */
/*   Updated: 2026/04/06 21:09:04 by advorace         ###   ########.fr       */
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

// ERROR CODES
typedef enum e_error {
    ERR_OK = 0,
    ERR_PARSE,
    ERR_MEMORY,
    ERR_SEMAPHORE,
    ERR_PROCESS,
	ERR_THREAD,
	ERR_FORK
} t_error;

// Semaphore name
#define SEM_FORKS "/sem_forks"
#define SEM_STATE "/sem_state"
#define SEM_PRINT "/sem_print"
#define SEM_MEAL "/sem_meal"
