/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:34:52 by jblaye            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:10 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	print_error(char *error)
{
	int	len;

	len = ft_strlen(error);
	return (write(2, error, ft_strlen(error)));
}

int	ocalloc(void **ptr, int nb, int size)
{
	if (size && nb * size / size != nb)
		return (print_error(ENOMEM), -1);
	*ptr = (void *) malloc (nb * size);
	if (!*ptr)
		return (print_error(ENOMEM), -1);
	memset(*ptr, 0, nb);
	return (0);
}

static void	ft_putchar(int a, int fd)
{
	char	c;

	c = a + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(time_t n, int fd)
{
	if (n < 0)
	{
		n = -n ;
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar(n % 10, fd);
	}
	else
	{
		ft_putchar(n % 10, fd);
	}
}
