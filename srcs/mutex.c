/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:35:06 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 15:06:26 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_var(t_mutex *var, int val)
{
	mlock(&var->mutex);
	var->n = val;
	munlock(&var->mutex);
}

int	get_var(t_mutex *var)
{
	int	i;

	mlock(&var->mutex);
	i = var->n;
	munlock(&var->mutex);
	return (i);
}

void	incr_var(t_mutex *var)
{
	mlock(&var->mutex);
	var->n += 1;
	munlock(&var->mutex);
}

void	lock_print(t_mutex *var, char *str)
{
	mlock(&var->mutex);
	write(1, str, ft_strlen(str));
	munlock(&var->mutex);
}
