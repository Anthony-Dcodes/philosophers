/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:32:05 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 13:54:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "limits.h"

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
		++i;
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
		++i;
	}
	if (result > INT_MAX)
		return (1);
	return (0);
}
