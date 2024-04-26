/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:36:45 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/26 10:17:46 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	isvalidarg(char *arg, int *rule, int isphilo, char *arg_name)
{
	long int	n;

	n = 0;
	while ((*arg >= 9 && *arg <= 13) || *arg == 32)
		arg++;
	if (*arg < '0' || *arg > '9')
		return (printf("Argument '%s' must be only numbers\n", arg_name), -1);
	while (*arg >= '0' && *arg <= '9')
	{
		n = n * 10 + (*arg - '0');
		if (n > INT_MAX || (isphilo == 1 && n > 400))
			return (printf("Argument '%s' is too high\n", arg_name), -1);
		arg++;
	}
	while ((*arg >= 9 && *arg <= 13) || *arg == 32)
		arg++;
	if (*arg != 0)
		return (printf("Argument '%s' must be only numbers\n", arg_name), -1);
	*rule = (int) n;
	return (0);
}

int	parsing(int ac, char *av[], t_rules *rules)
{
	if (ac < 5 || ac > 6)
		return (-1);
	if (isvalidarg(av[NB_PHILO], &rules->nb_philo, 1, "number_of_philos") == -1)
		return (-1);
	if (isvalidarg(av[TIME_DIE], &rules->time_die, 0, "time_to_die") == -1)
		return (-1);
	if (isvalidarg(av[TIME_EAT], &rules->time_eat, 0, "time_to_eat") == -1)
		return (-1);
	if (isvalidarg(av[TIME_SLEEP], &rules->time_sleep, 0, "time_to_sleep") == -1)
		return (-1);
	if (ac == 6
		&& isvalidarg(av[NB_EAT], &rules->nb_meals, 0, "number_of_meals") == -1)
		return (-1);
	return (0);
}
