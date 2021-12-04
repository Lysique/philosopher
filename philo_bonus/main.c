/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:57:36 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/04 09:54:05 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;

	philo = philo_init(argc, argv);
	if (!philo)
		return (0);
	semaphores_init(philo);
}
