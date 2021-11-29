/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:55:41 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 11:27:41 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb(int nb)
{
	int	length;

	length = 1;
	while (nb / length >= 10)
		length *= 10;
	while (length)
	{
		ft_putchar(nb / length + '0');
		nb = nb % length;
		length = length / 10;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_write(int time, int name, char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	ft_putnb(time);
	ft_putchar(' ');
	ft_putnb(name);
	ft_putchar(' ');
	ft_putstr(str);
	pthread_mutex_unlock(philo->write);
}
