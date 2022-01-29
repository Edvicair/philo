/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:08:51 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:23:03 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

t_infos	*max_eat(int ac, char **av, t_infos *infos)
{
	if (ac == 5)
		infos->max_eat = -1;
	else
		infos->max_eat = ft_atoi(av[5]);
	return (infos);
}

t_infos	*fill_info(int ac, char **av)
{
	int		i;
	t_infos	*infos;

	i = 0;
	infos = malloc(sizeof(t_infos));
	if (!infos)
		return (NULL);
	infos->n_philo = ft_atoi(av[1]);
	infos->ttd = ft_atoi(av[2]);
	infos->tte = ft_atoi(av[3]);
	infos->tts = ft_atoi(av[4]);
	infos->die = 0;
//	pthread_mutex_init(&infos->die, NULL);
	pthread_mutex_init(&infos->write, NULL);
	infos->fork = malloc(sizeof(pthread_mutex_t) * infos->n_philo);
	if (!infos->fork)
		return (NULL);
	if (i < infos->n_philo)
	{
		pthread_mutex_init(&infos->fork[i], NULL);
		i++;
	}
	infos = max_eat(ac, av, infos);
	return (infos);
}

long	ft_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, (void *)0);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}

t_philo	*ft_create(t_infos *infos, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->id = id;
	philo->info_ptr = infos;
	philo->next = NULL;
	philo->last_meal = 0;
	philo->time = ft_time();
	philo->p_max_eat = infos->max_eat;
	return (philo);
}

t_philo	*fill_philo(t_infos *infos)
{
	t_philo	*philo;
	t_philo	*in;
	int		i;

	i = 0;
	philo = NULL;
	while (i < infos->n_philo)
	{
		if (!philo)
			philo = ft_create(infos, i + 1);
		else
		{
			in = ft_create(infos, i + 1);
			ft_lstadd_back(&philo, in);
		}
		i++;
	}
	ft_lstadd_back(&philo, philo);
	return (philo);
}
