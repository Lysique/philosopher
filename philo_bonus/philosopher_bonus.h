/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:07:28 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/04 09:40:45 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <errno.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_philo {
	int		nb_philo;
	int		t_to_die;
	int		t_to_sleep;
	int		t_to_eat;
	int		nb_times_to_eat;
	int		last_eat;
	int		name;
	int		*end;
	sem_t	*forks;
	sem_t	*write;
	sem_t	*is_dead;
	sem_t	*is_finished;
}				t_philo;

int		ft_get_time(void);
t_philo	*philo_init(int argc, char **argv);

int		semaphores_init(t_philo *philo);

void	ft_write(int time, int name, char *str, t_philo *philo);

int		free_all(t_philo *philo);
int		free_my_ptrs(void *ptr1, void *ptr2, void *ptr3, void *ptr4);

void	routine(t_philo *philo);

#endif
