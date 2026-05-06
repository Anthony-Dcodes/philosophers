/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_loop_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:25:50 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 09:37:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "structs.h"
#include "error.h"
#include "pthread.h"
#include "child.h"

int	initialize_philosopher_thread(t_philosopher *philosopher, int i)
{
	int	ret;

	ret = ERR_OK;
	philosopher->id = i + 1;
	ret = pthread_create(&philosopher->thread, NULL,
			philosopher_loop, philosopher);
	if (ret != ERR_OK)
		return (ERR_THREAD);
	philosopher->sim->flags.thread_created = 1;
	ret = pthread_create(&philosopher->destroy_thread, NULL,
			child_destroy_thread, philosopher);
	if (ret != ERR_OK)
		return (ERR_THREAD);
	philosopher->sim->flags.destroy_thread_created = 1;
	return (ret);
}
