/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 17:24:33 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <limits.h>

# define MUTEX_INIT_FAIL "Failed to initialize mutex\n"
# define THREAD_CREATE_ERR "Failed to create thread\n"
# define ENOMEM "Not enough space/ cannot allocate memory\n"

# define RUN 1
# define STOP 0

# define TOOK_FORK "has taken a fork"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define THINKING "is thinking"
# define DIED "died"

typedef enum e_pars
{
	NB_PHILO = 1,
	TIME_DIE,
	TIME_EAT,
	TIME_SLEEP,
	NB_EAT
}			t_pars;

typedef struct s_rules
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_meals;
}				t_rules;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				n;
}				t_mutex;

// le int de run sert a checker si un philo est mort
typedef struct s_global
{
	t_mutex	run;
	t_mutex	done_eating;
	t_mutex	write;
	time_t	s_time;
}				t_global;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	time_t			last_meal;
	t_global		*g_vars;
	t_rules			*rules;
	t_mutex			left_fork;
	t_mutex			*right_fork;
}					t_philo;

/// FLEMME-VIE
int		mlock(pthread_mutex_t *mutex);
int		munlock(pthread_mutex_t *mutex);
int		mdestroy(pthread_mutex_t *mutex);

/// INIT
int		init_mutex(t_mutex *m, int val);
void	init_rules(t_rules *rules);
int		init_g_vars(t_global *g_vars);
void	init_philo(t_philo *philo, t_global *g_vars, t_rules *rules, int i);
int		init_philos(t_philo *philos, t_global *g_vars, t_rules *rules);

/// UTILS
int		ft_strlen(char *str);
int		print_error(char *error);
int		ocalloc(void **ptr, int nb, int size);
void	ft_putnbr_fd(time_t n, int fd);
void	set_var(t_mutex *var, int val);
int		get_var(t_mutex *var);
void	incr_var(t_mutex *var);
void	print_state(t_mutex *var, int id, time_t time, char *event);
int		print_time_state(t_philo *philo, char *event);
int		get_time(t_global *g_vars, time_t *time);
int		ft_usleep(t_philo *philo, time_t sleep_time);

/// PARSING
int		parsing(int ac, char *av[], t_rules *rules);

/// CORE
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
int		isphilodead(t_philo *philo);
void	*routine(void *arg);

#endif