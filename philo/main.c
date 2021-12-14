/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:03:22 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 14:31:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	shared_variables(t_philo *philo, int *is_dead, int *is_finished)
{
	int	i;

	i = 0;
	*is_dead = 0;
	*is_finished = 0;
	while (i < philo->nb_philo)
	{
		philo[i].is_dead = is_dead;
		philo[i].is_finished = is_finished;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		error;
	int		is_dead;
	int		is_finished;

	philo = philo_init(argc, argv);
	if (!philo)
		return (1);
	shared_variables(philo, &is_dead, &is_finished);
	error = ft_philosopher(philo);
	ft_free(philo, error);
	if (error)
		return (1);
	return (0);
}
