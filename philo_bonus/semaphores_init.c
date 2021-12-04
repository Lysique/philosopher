/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:12:31 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/04 09:55:15 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*processes_init(void *arg)
{
	int		i;
	int		pid;
	t_philo	*philo;

	philo = (t_philo *)arg;
	pid = fork();
	if (pid != 0)
		return (0);
	i = 0;
	while (i < philo->nb_philo)
	{
		pid = fork();
		if (pid != 0)
		{
			routine(&philo[i]);
			break ;
		}
		i++;
	}
	return (0);
}

void	*check_if_finished(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	while (i++ < philo->nb_philo)
		sem_wait(philo->is_finished);
	sem_post(philo->is_dead);
	return (0);
}

void	wait_for_death(t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(philo->is_dead);
	while (i < philo->nb_philo)
	{
		sem_post(philo->is_finished);
		i++;
	}
}

int	thread_init(t_philo *philo)
{
	pthread_t	processes;
	pthread_t	finished;

	if (pthread_create(&processes, 0, &processes_init, philo))
		return (free_all(philo));
	pthread_join(processes, 0);
	if (pthread_create(&finished, 0, &check_if_finished, philo))
		return (free_all(philo));
	wait_for_death(philo);
	pthread_join(finished, 0);
	free_all(philo);
	kill(0, SIGINT);
	return (0);
}

int	semaphores_init(t_philo *philo)
{
	int		i;
	sem_t	*forks;
	sem_t	*write;
	sem_t	*is_dead;
	sem_t	*is_finished;

	i = 0;
	forks = sem_open("forks", O_CREAT, 0600, philo->nb_philo);
	write = sem_open("write", O_CREAT, 0600, 1);
	is_finished = sem_open("finished", O_CREAT, 0600, 0);
	is_dead = sem_open("dead", O_CREAT, 0600, 0);
	while (i < philo->nb_philo)
	{
		philo[i].is_finished = is_finished;
		philo[i].is_dead = is_dead;
		philo[i].write = write;
		philo[i].forks = forks;
		i++;
	}
	return (thread_init(philo));
}
