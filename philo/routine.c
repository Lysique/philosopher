/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:26:23 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 15:25:01 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_get_time(int start)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, 0);
	time = 0;
	time += (tv.tv_sec % 1000) * 1000;
	time += tv.tv_usec / 1000;
	time -= start;
	return (time);
}

int	ft_think(t_philo *philo)
{
	int	time;

	time = ft_get_time(philo->start);
	if (*philo->is_dead)
		return (1);
	ft_write(ft_get_time(philo->start), philo->name, "is thinking\n", philo);
	pthread_mutex_lock(&philo->forks[philo->right]);
	if (*philo->is_dead)
		return (1);
	ft_write(ft_get_time(philo->start), philo->name,
		"has taken a fork\n", philo);
	pthread_mutex_lock(&philo->forks[philo->left]);
	if (*philo->is_dead)
		return (1);
	ft_write(ft_get_time(philo->start), philo->name,
		"has taken a fork\n", philo);
	return (0);
}

int	ft_eat_and_sleep(t_philo *philo)
{
	int	time;

	philo->last_eat = ft_get_time(philo->start);
	ft_write(ft_get_time(philo->start), philo->name, "is eating\n", philo);
	while (ft_get_time(philo->start) - philo->last_eat < philo->t_to_eat)
	{
		if (*philo->is_dead)
			return (1);
		usleep(500);
	}
	pthread_mutex_unlock(&philo->forks[philo->right]);
	pthread_mutex_unlock(&philo->forks[philo->left]);
	ft_write(ft_get_time(philo->start), philo->name, "is sleeping\n", philo);
	if (!philo->nb_times_to_eat)
		return (0);
	time = ft_get_time(philo->start);
	while (ft_get_time(philo->start) - time < philo->t_to_sleep)
	{	
		if (*philo->is_dead)
			return (1);
		usleep(500);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->nb_times_to_eat)
	{
		if (philo->nb_times_to_eat > 0)
			philo->nb_times_to_eat--;
		if (ft_think(philo))
			return (0);
		if (ft_eat_and_sleep(philo))
			return (0);
	}
	(*philo->is_finished)++;
	return (0);
}
