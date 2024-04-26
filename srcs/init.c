/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:04:56 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/26 09:28:53 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_rules(t_rules *rules)
{
	rules->nb_meals = -1;
	rules->nb_philo = -1;
	rules->time_die = -1;
	rules->time_eat = -1;
	rules->time_sleep = -1;
}
