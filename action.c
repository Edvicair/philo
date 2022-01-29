/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:57:38 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:29:05 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long time, t_philo *philo, int verif)
{
	long	goal;

	goal = ft_time() + time;
	if (verif == 1)
	{
		while (ft_time() < goal)
			usleep(1);
	}
	else
	{
		if (!philo->info_ptr->die)
			usleep(time * 1000);
	}
}

void	action(t_philo *philo, char *str)
{
	if (philo->info_ptr->die == 0)
	{
		if (str[3] == 'e')
		{	
			lock_fork(philo);
			ft_write_philo(philo, str);
			philo->p_max_eat--;
			philo->last_meal = ft_time() - philo->time;
			ft_sleep(philo->info_ptr->tte, philo, 0);
		}
		else if (str[3] == 's')
		{
			ft_write_philo(philo, str);
			unlock_fork(philo);
			ft_sleep(philo->info_ptr->tts, philo, 0);
		}
		else
			ft_write_philo(philo, str);
	}
}

void	ft_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info_ptr->m_die);
	if (philo->info_ptr->n_philo == 1)
	{
		philo->info_ptr->die = philo->id;
		pthread_mutex_unlock(&philo->info_ptr->m_die);
	}
	while (philo->info_ptr->die == 0)
	{
		if ((ft_time() - philo->time
				- philo->last_meal >= philo->info_ptr->ttd))
		{
			philo->info_ptr->die = philo->id;
			ft_write_philo(philo, "died\n");
			pthread_mutex_unlock(&philo->info_ptr->m_die);
		}
		philo = philo->next;
	}
}
