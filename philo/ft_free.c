/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:08:51 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 15:36:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_free(t_philo *philo, int error)
{
	if (error == 0)
		return (0);
	if (error == 1)
	{
		free(philo->is_dead);
		free(philo->is_finished);
		free(philo);
	}
	else if (error == 2)
		pthread_mutex_destroy(philo->end);
	else if (error == 3)
		pthread_mutex_destroy(philo->write);
	else if (error == 4)
		free(philo->forks);
	else if (error == 5)
	{
		while (philo->nb_philo--)
			pthread_mutex_destroy(&philo->forks[philo->nb_philo]);
	}
	return (ft_free(philo, error - 1));
}
