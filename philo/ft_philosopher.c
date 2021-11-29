/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:58:24 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 15:35:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	death_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_get_time() - philo[i].last_eat > philo[i].t_to_die && philo[i].nb_times_to_eat)
		{
			ft_write(ft_get_time(), philo[i].name, "died\n", philo);
			*philo->is_dead = 1;
			i = 0;
			while (i < philo->nb_philo)
				pthread_mutex_unlock(&philo->forks[i++]);
			pthread_mutex_unlock(philo->end);
			break ;
		}
		if (*philo->is_finished == philo->nb_philo)
			break ;
		i++;
		if (i == philo->nb_philo)
			i = 0;
		usleep(50);
	}
}

int	thread_init(t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * philo->nb_philo);
	if (!thread)
		return (5);
	while (i < philo->nb_philo)
	{
		if (pthread_create(&thread[i], 0, &routine, &philo[i]))
		{
			while (i--)
				pthread_join(thread[i], 0);
			free(thread);
			return (5);
		}
		usleep(100);
		i++;
	}
	death_checker(philo);
	pthread_mutex_lock(philo->end);
	usleep(1000);
	while (i--)
		pthread_join(thread[i], 0);
	free(thread);
	return (ft_free(philo, 5));
}

int	forks_init(t_philo *philo, pthread_mutex_t end, pthread_mutex_t write)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;	
	forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!forks)
		return (3);
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], 0))
		{
			while (i--)
				pthread_mutex_destroy(&forks[i]);
			return (4);
		}
		i++;
	}
	while (i--)
	{
		philo[i].end = &end;
		philo[i].write = &write;
		philo[i].forks = forks;
	}
	return (thread_init(philo));
}

int	ft_philosopher(t_philo *philo)
{
	pthread_mutex_t	end;
	pthread_mutex_t	write;

	if (pthread_mutex_init(&end, 0))
		return (1);
	if (pthread_mutex_init(&write, 0))
		return (2);
	pthread_mutex_lock(&end);
	return (forks_init(philo, end, write));
}
