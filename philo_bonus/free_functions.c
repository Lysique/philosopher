/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:14:39 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 14:42:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	free_all(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->write);
	sem_close(philo->is_finished);
	sem_close(philo->is_dead);
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("finished");
	sem_unlink("dead");
	free(philo);
	return (0);
}
