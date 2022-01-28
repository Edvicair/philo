/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:35:52 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/18 18:06:03 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "struct.h"
# include <stdlib.h>

int		ft_atoi(char const *s);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_itoa(int n, unsigned int j);
size_t	ft_strlen(const char *str);
t_philo	*ft_lstlast(t_philo *philo);
void	ft_lstadd_back(t_philo **alst, t_philo *new);

#endif
