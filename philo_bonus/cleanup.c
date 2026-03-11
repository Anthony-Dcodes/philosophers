/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 23:12:58 by advorace          #+#    #+#             */
/*   Updated: 2026/03/11 22:05:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	cleanup_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_STATE);
}

void	clean_up(void)
{
	sem_close(SEM_FORKS);
	sem_close(SEM_MEAL);
	sem_close(SEM_PRINT);
	sem_close(SEM_STATE);
	cleanup_semaphores();
}
