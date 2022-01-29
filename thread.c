/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:00:39 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:01:12 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread(t_philo *philo)
{
	int		i;
	t_philo	*cpy;
	t_infos	*infos;

	infos = philo->info_ptr;
	i = infos->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_create(&cpy->t_id, NULL, (void *)&ft_loop, cpy);
		cpy = cpy->next;
		i--;
	}
}

void	ft_join(t_philo *philo)
{
	int		i;
	t_philo	*cpy;
	t_infos	*infos;

	infos = philo->info_ptr;
	i = infos->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_join(cpy->t_id, NULL);
		cpy = cpy->next;
		i--;
	}
}
