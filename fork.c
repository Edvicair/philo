/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:58:22 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:16:00 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (philo->info_ptr->die)
		return ;
	if (philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(fork);
		ft_write_philo(philo, "has taken a fork\n");
	}
}

void	lock_fork(t_philo *philo)
{	
	ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
	ft_fork(philo, &philo->info_ptr->fork[philo->next->id - 1]);
}

void	unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->next->id - 1]);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->id - 1]);
}
