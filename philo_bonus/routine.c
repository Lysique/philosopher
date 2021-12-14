/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:39:08 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 15:23:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*dead_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (*philo->end)
			break ;
		if (ft_get_time(philo->start) - philo->last_eat > philo->t_to_die)
		{
			*philo->end = 1;
			ft_write(ft_get_time(philo->start), philo->name, "is dead\n", philo);
			sem_post(philo->is_dead);
			break ;
		}
		usleep(500);
	}
	return (0);
}

int	ft_think(t_philo *philo)
{
	ft_write(ft_get_time(philo->start), philo->name, "is thinking\n", philo);
	sem_wait(philo->forks);
	ft_write(ft_get_time(philo->start), philo->name,
		"has taken a fork\n", philo);
	sem_wait(philo->forks);
	ft_write(ft_get_time(philo->start), philo->name,
		"has taken a fork\n", philo);
	return (0);
}

int	ft_eat_and_sleep(t_philo *philo)
{
	int	time;

	philo->last_eat = ft_get_time(philo->start);
	if (*philo->end)
		return (1);
	ft_write(ft_get_time(philo->start), philo->name, "is eating\n", philo);
	while (ft_get_time(philo->start) - philo->last_eat < philo->t_to_eat)
		usleep(500);
	sem_post(philo->forks);
	sem_post(philo->forks);
	ft_write(ft_get_time(philo->start), philo->name, "is sleeping\n", philo);
	if (!philo->nb_times_to_eat)
		return (0);
	time = ft_get_time(philo->start);
	while (ft_get_time(philo->start) - time < philo->t_to_sleep)
		usleep(500);
	return (0);
}

void	routine(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, 0, &dead_checker, philo))
		return ;
	while (philo->nb_times_to_eat)
	{
		if (philo->nb_times_to_eat > 0)
			philo->nb_times_to_eat--;
		if (ft_think(philo))
			break ;
		if (ft_eat_and_sleep(philo))
			break ;
	}
	*philo->end = 1;
	pthread_join(thread, 0);
	sem_post(philo->is_finished);
	return ;
}
