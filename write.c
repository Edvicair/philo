#include "struct.h"
#include "philo.h"
#include "libft.h"

char	*ft_cpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *one, char *two, int verif)
{
	char		*ret;
	size_t		size;

	size = ft_strlen(one) + ft_strlen(two) + 3;
	ret = malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ret = ft_cpy(ret, one);
	ret = ft_cpy(ret, " ");
	free(one);
	ret = ft_cpy(ret, two);
	if (verif)
		free(two);
	return (ret);
}

void	ft_write_philo(t_philo *philo, char *str)
{
	char	*ret;

	ret = NULL;
	pthread_mutex_lock(&philo->info_ptr->write);
	if (!philo->info_ptr->die)
	{
		ret = ft_strdup(ft_itoa(ft_time() - philo->time, 0),
				ft_itoa(philo->id, 0), 1);
		ret = ft_strdup(ret, str, 0);
		write(1, ret, ft_strlen(ret));
		free(ret);
	}
	else if (philo->id == philo->info_ptr->die)
	{
		ret = ft_strdup(ft_itoa(ft_time() - philo->time, 0),
				ft_itoa(philo->id, 0), 1);
		ret = ft_strdup(ret, str, 0);
		write(1, ret, ft_strlen(ret));
		free(ret);
	}
	pthread_mutex_unlock(&philo->info_ptr->write);
}
