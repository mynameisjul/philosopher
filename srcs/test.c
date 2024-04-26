#include "philo.h"

int main(int ac, char **av)

{
	t_rules	rules;

	init_rules(&rules);
	if (parsing(ac, av, &rules) == -1)
		printf("failed\n");
	printf("NB PHILO = %d\n \
			TIME DIE = %d\n \
			TIME EAT = %d\n \
			TIME SLEEP = %d\n \
			NB MEALS = %d\n", rules.nb_philo, rules.time_die, rules.time_eat, rules.time_sleep, rules.nb_meals);
	return (0);
}
