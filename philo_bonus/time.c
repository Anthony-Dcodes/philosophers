/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:14:37 by advorace          #+#    #+#             */
/*   Updated: 2026/03/04 16:12:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_timestamp_ms(void)
{
	struct timeval	tp;
	long			timestamp_ms;

	gettimeofday(&tp, NULL);
	timestamp_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (timestamp_ms);
}
