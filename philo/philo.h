/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:16:53 by advorace          #+#    #+#             */
/*   Updated: 2026/02/03 22:29:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <unistd.h> // write, usleep,
# include <sys/time.h> // gettimeofday

/*
pthread_create - create new thread
pthread_detach - detach a thread (alternative to pthread_join)
pthread_join - wait for a thread to finish
pthread_mutex_init - initialize mutex (lock, each for will be a mutex)
pthread_mutex_destroy - destroy / cleanup a mutex
pthread_mutex_lock - lock a mutex (acquire the fork, block if already locked by another thread)
pthread_mutex_unlock - unlock a mutex (release the fork), allows other threads to acquire it
*/
# include <pthread.h>

#endif
