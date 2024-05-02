/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:04:56 by jblaye            #+#    #+#             */
/*   Updated: 2024/05/02 10:49:02 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_mutex *m, int val)
{
	if (pthread_mutex_init(&m->mutex, NULL) != 0)
		return (print_error(MUTEX_INIT_FAIL), -1);
	m->n = val;
	return (0);
}

void	init_rules(t_rules *rules)
{
	rules->nb_meals = -1;
	rules->nb_philo = -1;
	rules->time_die = -1;
	rules->time_eat = -1;
	rules->time_sleep = -1;
}

int	init_g_vars(t_global *g_vars)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	g_vars->s_time = tv.tv_sec * 1000000 + tv.tv_usec;
	if (init_mutex(&g_vars->done_eating, 0))
		return (-1);
	if (init_mutex(&g_vars->run, 0))
		return (pthread_mutex_destroy(&g_vars->done_eating.mutex), -1);
	if (init_mutex(&g_vars->write, 0))
		return (pthread_mutex_destroy(&g_vars->done_eating.mutex),
			pthread_mutex_destroy(&g_vars->run.mutex), -1);
	return (0);
}

void	init_philo(t_philo *philo, t_global *g_vars, t_rules *rules, int i)
{
	philo->g_vars = g_vars;
	philo->id = i + 1;
	philo->last_meal = 0;
	philo->meals_eaten = 0;
	philo->rules = rules;
	philo->g_vars = g_vars;
}

int	init_philos(t_philo *philos, t_global *g_vars, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		init_philo(&(philos[i]), g_vars, rules, i);
		if (init_mutex(&(philos[i].left_fork), 0) != 0)
			return (-1);
		if (pthread_create(&(philos[i].thread), NULL, &routine, &philos[i]))
			return (print_error(THREAD_CREATE_ERR), -1);
		i++;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		philos[i].right_fork = &(philos[(i + 1)
				% philos->rules->nb_philo].left_fork);
		i++;
	}
	return (0);
}
