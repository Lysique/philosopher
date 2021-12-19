/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:06:34 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/19 11:45:17 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *c)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (-1);
		num = num * 10;
		num = num + c[i] - '0';
		if (num > 2147483647)
			return (-1);
		i++;
	}
	return (num);
}

int	check_params(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (-1);
	if (ft_atoi(argv[2]) < 60)
		return (-1);
	if (ft_atoi(argv[3]) < 60)
		return (-1);
	if (ft_atoi(argv[4]) < 60)
		return (-1);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (-1);
	return (1);
}

void	variables_init(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].start = ft_get_time(0);
		philo[i].last_eat = 0;
		philo[i].name = i + 1;
		philo[i].nb_philo = ft_atoi(argv[1]);
		philo[i].t_to_die = ft_atoi(argv[2]);
		philo[i].t_to_eat = ft_atoi(argv[3]);
		philo[i].t_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].nb_times_to_eat = ft_atoi(argv[5]);
		else
			philo[i].nb_times_to_eat = -1;
		philo[i].right = philo[i].name - 1;
		philo[i].left = philo[i].name % philo[i].nb_philo;
		i++;
	}
}

t_philo	*philo_init(int argc, char **argv)
{
	t_philo	*philo;

	if (check_params(argc, argv) == -1)
		return (0);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	variables_init(argc, argv, philo);
	return (philo);
}
