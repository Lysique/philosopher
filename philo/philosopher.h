/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:14:58 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/29 15:03:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				nb_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				nb_times_to_eat;
	int				last_eat;
	int				name;
	int				right;
	int				left;
	int				*is_dead;
	int				*is_finished;
	pthread_mutex_t	*end;
	pthread_mutex_t	*write;
	pthread_mutex_t	*forks;
}				t_philo;

t_philo	*philo_init(int argc, char **argv);

int		ft_philosopher(t_philo *philo);

void	ft_write(int time, int name, char *str, t_philo *philo);
int		ft_get_time(void);

void	*routine(void *arg);

int		ft_free(t_philo *philo, int error);

#endif
