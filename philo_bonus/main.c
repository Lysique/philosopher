/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:57:36 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 14:42:42 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	int			end;

	philo = philo_init(argc, argv, &end);
	if (!philo)
		return (0);
	semaphores_init(philo);
}
