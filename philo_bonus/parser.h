/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:04:58 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 13:05:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Parsing
int		parser_args(int argc, char *argv[], t_simulation *t_simulation);
int		is_int(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		is_more_then_int_max(char *nptr);
