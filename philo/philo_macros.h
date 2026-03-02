/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:55:53 by codespace         #+#    #+#             */
/*   Updated: 2026/03/02 11:40:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MACROS_H
# define PHILO_MACROS_H

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
    ERR_MUTEX,
    ERR_THREAD
} t_error;

#endif