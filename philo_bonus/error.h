/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:36:14 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 14:12:36 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// ERROR CODES
typedef enum e_error
{
	ERR_OK = 0,
	ERR_PARSE,
	ERR_MEMORY,
	ERR_SEMAPHORE,
	ERR_PROCESS,
	ERR_THREAD,
	ERR_FORK,
	ERR_DIED
}	t_error;

// Error functions
int		wrong_number_format(void);
int		not_an_int(void);
int		wrong_number_of_args(void);
