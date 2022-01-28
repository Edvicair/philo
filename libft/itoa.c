#include "libft.h"

unsigned int	ft_sign(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

unsigned int	ft_count(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb == 0)
		return (2);
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count + 1);
}

char	*ft_itoa(int n, unsigned int j)
{
	char			*res;
	unsigned int	nb;
	unsigned int	count;

	nb = ft_sign(n);
	count = ft_count(nb);
	if (n < 0)
	{
		count++;
		j = 1;
	}
	res = (char *)malloc(sizeof(char) * count);
	if (!(res))
		return (NULL);
	res[--count] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (count > j)
	{
		res[--count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
