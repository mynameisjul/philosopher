/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:32:34 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:59 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_global *g_vars, time_t *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	*time = -g_vars->s_time + tv.tv_sec * 1000000 + tv.tv_usec;
	return (0);
}

int	ft_usleep(t_philo *philo, time_t sleep_time)
{
	time_t	end_time;
	time_t	cu_time;

	if (get_time(philo->g_vars, &cu_time))
		return (1);
	end_time = cu_time + sleep_time;
	while (cu_time < end_time)
	{
		usleep(1000);
		if (get_time(philo->g_vars, &cu_time))
			return (-1);
		if (isphilodead(philo))
			return (-1);
	}
	return (0);
}
