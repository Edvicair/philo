/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:42:59 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/18 20:00:01 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philo.h"

int	parsing_bis(char **av, char *str, int i, int nb)
{
	if (ft_strncmp(str, av[i], ft_strlen(av[i])))
	{
		printf("Error : Arg is not number\n");
		free(str);
		return (1);
	}
	else if (nb < 0)
	{
		printf("Error : Not negative number\n");
		free(str);
		return (1);
	}
	else if ((i == 1 || i == 2 || i == 5) && nb == 0)
	{
		printf("Error : Need number > 0 for ");
		printf("[nb_philo][time_to_die][nb_eat]\n");
		free(str);
		return (1);
	}
	return (0);
}

int	parsing(int ac, char **av)
{
	char	*str;
	int		i;
	int		nb;

	i = 1;
	if (!(ac == 5 || ac == 6))
	{
		printf("Error : Not right nb of arg\n");
		return (1);
	}
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		str = ft_itoa(nb, 0);
		if (parsing_bis(av, str, i, nb))
			return (1);
		free(str);
		i++;
	}
	return (0);
}
