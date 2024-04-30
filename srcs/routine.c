/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:43:16 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 18:20:33 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo, t_mutex *fork)
{
	while (get_var(fork) != 0)
		if (ft_usleep(philo, 100))
			return (-1);
	set_var(fork, philo->id);
	if (isphilodead(philo) || print_time_state(philo, TOOK_FORK))
		return (-1);
	return (0);
}

int	eating(t_philo *philo)
{
	time_t	time;

	if (take_fork(philo, &philo->left_fork)
		|| take_fork(philo, philo->right_fork))
		return (-1);
	if (print_time_state(philo, EATING)
		|| get_time(philo->g_vars, &time)
		|| ft_usleep(philo, philo->rules->time_eat))
		return (-1);
	philo->last_meal = time + (time_t) philo->rules->time_eat;
	if (philo->rules->nb_meals != -1)
		if (++philo->meals_eaten == philo->rules->nb_meals)
			incr_var(&philo->g_vars->done_eating);
	set_var(&philo->left_fork, 0);
	if (isphilodead(philo))
		return (-1);
	set_var(philo->right_fork, 0);
	if (isphilodead(philo))
		return (-1);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_time_state(philo, SLEEPING))
		return (-1);
	if (ft_usleep(philo, philo->rules->time_sleep))
		return (-1);
	return (0);
}

int	isphilodead(t_philo *philo)
{
	struct timeval	tv;
	time_t			time;

	if (get_var(&philo->g_vars->run) == STOP)
		return (-1);
	if (gettimeofday(&tv, NULL))
		return (-1);
	time = philo->g_vars->s_time - tv.tv_sec * 1000000 - tv.tv_usec;
	if (time - philo->last_meal > philo->rules->time_die)
		return (set_var(&philo->g_vars->run, STOP),
			print_state(&philo->g_vars->write, philo->id, time, DIED), -1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (get_var(&philo->g_vars->run) == STOP)
		usleep(1000);
	if (philo->id % 2 == 0)
		usleep(1000);
	if (isphilodead(philo))
		return (NULL);
	while (!eating(philo) && !sleeping(philo)
		&& !print_time_state(philo, THINKING))
		;
	return (NULL);
}
