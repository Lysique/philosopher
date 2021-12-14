/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:08:51 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 14:31:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_free(t_philo *philo, int error)
{
	if (error == 0)
		return (0);
	else if (error == 1)
		free(philo);
	else if (error == 2)
		pthread_mutex_destroy(philo->write);
	else if (error == 3)
		free(philo->forks);
	else if (error == 4)
	{
		while (philo->nb_philo--)
			pthread_mutex_destroy(&philo->forks[philo->nb_philo]);
	}
	return (ft_free(philo, error - 1));
}
