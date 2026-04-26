/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:25:50 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 12:25:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
