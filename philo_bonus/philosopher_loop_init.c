/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:25:50 by advorace          #+#    #+#             */
/*   Updated: 2026/04/27 13:57:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "structs.h"
#include "error.h"
#include "pthread.h"

int	initialize_philosopher_thread(t_philosopher *philosopher, int i)
{
	int	ret;

	ret = ERR_OK;
	philosopher->id = i + 1;
	ret = pthread_create(&philosopher->thread, NULL,
			philosopher_loop, philosopher);
	if (ret != ERR_OK)
	{
		ret = ERR_THREAD;
		return (ret);
	}
	philosopher->sim->flags.thread_created = 1;
	return (ret);
}
