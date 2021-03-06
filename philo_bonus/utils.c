/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:19:01 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/14 14:45:47 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	ft_get_time(int start)
{
	struct timeval	tv;
	int				time;

	time = 0;
	gettimeofday(&tv, 0);
	time += tv.tv_usec / 1000;
	time += (tv.tv_sec % 1000) * 1000;
	time -= start;
	return (time);
}
