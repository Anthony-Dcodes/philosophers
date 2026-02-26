/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:14:37 by advorace          #+#    #+#             */
/*   Updated: 2026/02/15 23:17:44 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp_ms(void)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (timestamp_ms);
}

void	set_last_meal_time(t_philosopher *philosopher)
{
	long			timestamp_ms;

	timestamp_ms = get_timestamp_ms();
	philosopher->last_meal = timestamp_ms;
}
