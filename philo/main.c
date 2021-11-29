/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:03:22 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 15:27:25 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		error;

	philo = philo_init(argc, argv);
	if (!philo)
		return (0);
	error = ft_philosopher(philo);
	ft_free(philo, error);
	return (0);
}
