/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:31:34 by advorace          #+#    #+#             */
/*   Updated: 2026/02/12 20:32:19 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal_time(t_philosopher *philosopher)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	philosopher->last_meal = timestamp_ms;
}
