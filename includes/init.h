/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:10:52 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:12:14 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "struct.h"
# include "libft.h"

int		parsing(int ac, char **av);
t_infos	*fill_info(int ac, char **av);
t_philo	*fill_philo(t_infos *infos);

#endif
