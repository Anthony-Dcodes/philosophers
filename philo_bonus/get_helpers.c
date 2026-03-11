/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:22:01 by codespace         #+#    #+#             */
/*   Updated: 2026/03/11 22:54:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int get_death(t_simulation *simulation)
{
    int value;

    sem_wait(simulation->state_semaphore);
    value = simulation->flags.philosopher_died;
    sem_post(simulation->state_semaphore);
    return (value);
}

int get_all_philosophers_full(t_simulation *simulation)
{
    int value;

    sem_wait(simulation->state_semaphore);
    value = simulation->flags.all_philosophers_full;
    sem_post(simulation->state_semaphore);
    return (value);
}

long get_last_meal(t_philosopher *philosopher)
{
    long value;

    sem_wait(philosopher->sim->meal_semaphore);
    value = philosopher->last_meal;
    sem_post(philosopher->sim->meal_semaphore);
    return (value);
}

int get_meals_eaten(t_philosopher *philosopher)
{
    int value;

    sem_wait(philosopher->sim->meal_semaphore);
    value = philosopher->meals_eaten;
    sem_post(philosopher->sim->meal_semaphore);
    return (value);
}
