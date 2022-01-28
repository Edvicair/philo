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
