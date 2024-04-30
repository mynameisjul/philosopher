/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flemme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:04:08 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:41 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mlock(pthread_mutex_t *mutex)
{
	return (pthread_mutex_lock(mutex));
}

int	munlock(pthread_mutex_t *mutex)
{
	return (pthread_mutex_unlock(mutex));
}

int	mdestroy(pthread_mutex_t *mutex)
{
	return (pthread_mutex_destroy(mutex));
}
