/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:00:11 by advorace          #+#    #+#             */
/*   Updated: 2026/04/26 13:00:40 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Get helpers
int		get_death(t_simulation *simulation);
int		get_philosopher_full(t_simulation *simulation);
long	get_last_meal(t_philosopher *philosopher);
int		get_meals_eaten(t_philosopher *philosopher);

// Set helpers
void	set_last_meal_time(t_philosopher *philosopher);
void	set_death(t_simulation *simulation, int id);
void	set_philosopher_full(t_simulation *simulation);
void	set_increment_meals_eaten(t_philosopher *philosopher);
