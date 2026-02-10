/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:01:43 by advorace          #+#    #+#             */
/*   Updated: 2026/02/10 23:22:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void static	mutex_var_init(t_simulation *simulation)
{
	simulation->death = 0;
}

int	mutex_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&simulation->death_mutex, NULL) != 0)
		return (1);
	mutex_var_init(simulation);
	return (0);
}
