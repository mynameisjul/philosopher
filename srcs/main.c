/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:23 by jblaye            #+#    #+#             */
/*   Updated: 2024/05/02 10:37:41 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_philo *philos, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (philos[i].thread)
			pthread_join(philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&philos[i].left_fork.mutex);
		i++;
	}
	pthread_mutex_destroy(&philos[0].g_vars->done_eating.mutex);
	pthread_mutex_destroy(&philos[0].g_vars->run.mutex);
	pthread_mutex_destroy(&philos[0].g_vars->write.mutex);
}

int	main(int ac, char *av[])
{
	t_rules		rules;
	t_global	g_vars;
	t_philo		philos[400];

	init_rules(&rules);
	if (parsing(ac, av, &rules) == -1)
		return (-1);
	if (init_g_vars(&g_vars))
		return (-1);
	init_philos(philos, &g_vars, &rules);
	set_var(&g_vars.run, RUN);
	while (get_var(&g_vars.run) == RUN)
	{
		usleep(1000);
		if (get_var(&g_vars.done_eating) != -1
			&& get_var(&g_vars.done_eating) >= rules.nb_philo)
		{
			set_var(&g_vars.run, STOP);
			break ;
		}
	}
	return (clean(philos, rules.nb_philo), 0);
}
