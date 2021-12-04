/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:06:34 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/04 12:06:27 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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

t_philo	variables_init2(int argc, char **argv, t_philo philo)
{
	philo.nb_philo = ft_atoi(argv[1]);
	philo.t_to_die = ft_atoi(argv[2]);
	philo.t_to_sleep = ft_atoi(argv[3]);
	philo.t_to_eat = ft_atoi(argv[4]);
	if (argc == 6)
		philo.nb_times_to_eat = ft_atoi(argv[5]);
	else
		philo.nb_times_to_eat = -1;
	philo.last_eat = ft_get_time();
	return (philo);
}

t_philo	*variables_init(int argc, char **argv, t_philo *philo)
{
	int		i;
	int		*end;

	i = 0;
	end = malloc(sizeof(int));
	if (!end)
	{
		free(philo);
		return (0);
	}
	*end = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].name = i + 1;
		philo[i].end = end;
		philo[i] = variables_init2(argc, argv, philo[i]);
		i++;
	}
	return (philo);
}

t_philo	*philo_init(int argc, char **argv)
{
	t_philo	*philo;

	if (check_params(argc, argv) == -1)
		return (0);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("finished");
	sem_unlink("dead");
	philo = variables_init(argc, argv, philo);
	return (philo);
}
