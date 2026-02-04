/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:31 by advorace          #+#    #+#             */
/*   Updated: 2026/02/04 21:56:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wrong_number_format(void)
{
	printf("Wrong number format!\n");
	printf("Use positive int without sign characters > 0!\n");
	printf("It also cannot start with 0!\n");
	return (0);
}

int	not_an_int(void)
{
	printf("Argument not a type(int)!\n");
	printf("All arguments must be type(int)!\n");
	printf("Max value for int: %d!\n", INT_MAX);
	return (0);
}

int	wrong_number_of_args(void)
{
	printf("Wrong number of argumens, 4 needed, 5 optionally!\n");
	printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep\n");
	printf("Optional argument: number_of_times_each_philosopher_must_eat\n");
	return (0);
}
