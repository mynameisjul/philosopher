/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:42:07 by jblaye            #+#    #+#             */
/*   Updated: 2024/05/02 11:13:53 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_mutex *var, int id, time_t time, char *event)
{
	mlock(&var->mutex);
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(id, 1);
	write(1, " ", 1);
	write(1, event, ft_strlen(event));
	write(1, "\n", 1);
	munlock(&var->mutex);
}

int	print_time_state(t_philo *philo, char *event)
{
	time_t	time;

	if (get_time(philo->g_vars, &time))
		return (-1);
	print_state(&philo->g_vars->write, philo->id, time / 1000, event);
	return (0);
}
