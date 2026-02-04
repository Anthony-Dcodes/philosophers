/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:55:13 by advorace          #+#    #+#             */
/*   Updated: 2026/02/04 21:57:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// If success - 0, else 1
int	parser_args(int argc, char *argv[], t_simulation *simulation)
{
	int	i;

	i = 1;
	if (argc != 5 || argc != 6)
	{
		wrong_number_of_args();
		return (1);
	}
	while (argv[i])
	{
		if (!is_int(argv[i]))
			return (1);
		++i;
	}
	simulation->n_philosophers = ft_atoi(argv[1]);
	simulation->n_forks = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	simulation->n_times_must_eat = ft_atoi(argv[5]);
	return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
			return (wrong_number_format());
		else if (!ft_isdigit(str[i]))
			return (not_an_int());
		++i;
	}
	if (i > 10 || is_more_then_int_max(str))
		return (not_an_int());
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result);
}

int	is_more_then_int_max(char *nptr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (1);
	return (0);
}
