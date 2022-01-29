/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:11:36 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:12:34 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "struct.h"

int		ft_max_eat(t_philo *philo);
void	ft_join(t_philo *philo);
void	ft_dead(t_philo *philo);
void	*ft_loop(t_philo *philo);
void	ft_thread(t_philo *philo);
void	lock_fork(t_philo *philo);
void	ft_monitoring(t_philo *philo);
void	unlock_fork(t_philo *philo);
void	action(t_philo *philo, char *str);
void	ft_write_philo(t_philo *philo, char *str);
void	ft_sleep(long time, t_philo *philo, int n);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
long	ft_time(void);

#endif
