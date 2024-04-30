/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:25:56 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 17:26:35 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* static void	print_params(t_rules rules)
{
	printf("NB PHILO = %d\n \
TIME DIE = %d\n \
TIME EAT = %d\n \
TIME SLEEP = %d\n \
NB MEALS = %d\n", \
rules.nb_philo, rules.time_die, rules.time_eat, rules.time_sleep, rules.nb_meals);
}

static void	print_globals(t_global g_vars)
{
	printf("DONE EATING MTX = %p\n \
			RUN MTX = %p\n \
			TIME = %d\n \
			WRITE MTX = %p\n", g_vars.done_eating.mutex, g_vars.run.mutex, g_vars.s_time, g_vars.write.mutex);
}

int main(int ac, char **av)
{
	t_philo	*philos;
	t_rules	rules;
	t_global g_vars;

	init_rules(&rules);
	philos = NULL;
	if (parsing(ac, av, &rules) == -1)
		return (-1);
	print_params(rules);
	if (init_g_vars(&g_vars))
		return (-1);
	if (ocalloc((void **)&philos, rules.nb_philo + 1, sizeof(t_philo)))
	 	return (-1);
	init_philos(philos, &g_vars, &rules);
	 t_mutex m;
	init_mutex(&m, 0);
	print_state(&m, atoi(av[1]), atoi(av[2]), av[ac - 1]);
	return (0);
}
*/