/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_destroy_thread.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 08:56:57 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 09:29:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

void	*child_destroy_thread(void *arg)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *)arg;
	sem_wait(philosopher->sim->destroy_semaphore);
	set_death(philosopher->sim, philosopher->id);
}
