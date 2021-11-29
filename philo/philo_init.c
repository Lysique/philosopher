/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:06:34 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 15:03:29 by tamighi          ###   ########.fr       */
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
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[2]) == -1
		|| ft_atoi(argv[3]) == -1 || ft_atoi(argv[4]) == -1
		|| (argc == 6 && ft_atoi(argv[5]) == -1))
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
	philo.last_eat = 0;	
	philo.right = philo.name - 1;
	philo.left = philo.name % philo.nb_philo;
	philo.last_eat = ft_get_time();
	return (philo);
}

t_philo	*variables_init(int argc, char **argv, t_philo *philo)
{
	int	i;
	int	*is_dead;
	int	*is_finished;

	i = 0;
	is_dead = malloc(sizeof(int));
	is_finished = malloc(sizeof(int));
	if (!is_dead || !is_finished)
	{
		free(philo);
		if (is_dead)
			free(is_dead);
		if (is_finished)
			free(is_finished);
		return (0);
	}
	while (i < ft_atoi(argv[1]))
	{
		philo[i].name = i + 1;
		philo[i].is_dead = is_dead;
		philo[i].is_finished = is_finished;
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
	philo = variables_init(argc, argv, philo);
	*philo->is_dead = 0;
	*philo->is_finished = 0;
	return (philo);
}
