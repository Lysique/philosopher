/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:08:51 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 16:04:04 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_my_ptrs(void *ptr1, void *ptr2, void *ptr3)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (ptr3)
		free(ptr3);
}

int	ft_free(t_philo *philo, int error)
{
	if (error == 0)
		return (0);
	if (error == 1)
		free_my_ptrs(philo->is_dead, philo->is_finished, philo);
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
