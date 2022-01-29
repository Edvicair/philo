/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:42:54 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:00:28 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"

void	ft_exit(t_philo *philo)
{
	t_philo	*cpy;
	int		i;

	i = 0;
	pthread_mutex_destroy(&philo->info_ptr->write);
	while (i < philo->info_ptr->n_philo)
	{
		pthread_mutex_destroy(&philo->info_ptr->fork[i]);
		i++;
	}
	free(philo->info_ptr->fork);
	i = philo->info_ptr->n_philo;
	while (i)
	{
		cpy = philo->next;
		free(philo);
		philo = cpy;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_infos	*infos;
	t_philo	*philo;

	if (parsing(ac, av))
		return (0);
	infos = fill_info(ac, av);
	philo = fill_philo(infos);
	infos->philo_ptr = philo;
	ft_thread(philo);
	ft_dead(philo);
	ft_join(philo);
	ft_exit(philo);
	free(infos);
	return (0);
}	
