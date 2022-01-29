/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:59:12 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 22:59:39 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_max_eat(t_philo *philo)
{
	t_philo	*cpy;

	cpy = philo;
	while (cpy->next->id != 1)
	{
		if (cpy->p_max_eat == 0)
			cpy = cpy->next;
		else
			return (0);
	}
	if (cpy->p_max_eat == 0)
		return (1);
	return (0);
}

void	ft_monitoring(t_philo *philo)
{
	if (philo->info_ptr->n_philo == 1)
	{
		philo->info_ptr->die = 1;
		return ;
	}
	action(philo, "is eating\n");
	action(philo, "is sleeping\n");
	action(philo, "is thinking\n");
}

void	*ft_loop(t_philo *philo)
{
	if (philo->id == 1 && philo->next->id == 1)
	{	
		ft_sleep((philo->info_ptr->ttd), philo, 1);
		ft_write_philo(philo, "died\n");
		return ((void *)0);
	}
	if (philo->info_ptr->n_philo % 2)
	{
		if (philo->id == philo->info_ptr->n_philo)
			ft_sleep(philo->info_ptr->tte * 2, philo, 0);
		else if (philo->id % 2)
			ft_sleep(philo->info_ptr->tte, philo, 0);
	}
	else if (philo->id % 2)
		ft_sleep(philo->info_ptr->tte, philo, 0);
	while ((philo->info_ptr->die == 0) && (ft_max_eat(philo) == 0))
	{
		if (philo->id <= philo->info_ptr->n_philo)
			ft_monitoring(philo);
	}
//	if (philo->info_ptr->die == philo->id)
//		ft_write_philo(philo, "died\n");
	return ((void *)0);
}
