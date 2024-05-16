/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:42:07 by jblaye            #+#    #+#             */
/*   Updated: 2024/05/16 09:23:10 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_time_state(t_philo *philo, char *event)
{
	time_t	time;

	mlock(&philo->g_vars->write.mutex);
	if (get_time(philo->g_vars, &time))
		return (-1);
	ft_putnbr_fd(time / 1000, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, " ", 1);
	write(1, event, ft_strlen(event));
	write(1, "\n", 1);
	munlock(&philo->g_vars->write.mutex);
	return (0);
}
