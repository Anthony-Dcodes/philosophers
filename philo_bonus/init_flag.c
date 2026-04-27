/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:26:51 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 14:13:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "structs.h"

void	init_flags(t_flags *flags)
{
	memset(flags, 0, sizeof(t_flags));
}
