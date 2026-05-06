/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 07:52:53 by advorace          #+#    #+#             */
/*   Updated: 2026/05/06 08:23:03 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

int		init_philo_full_thread(t_philosopher *philosopher);
void	*philo_full_thread(void	*arg);
void	terminate_philo_full_thread(t_philosopher *philosopher);
