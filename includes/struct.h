/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:03:00 by edvicair          #+#    #+#             */
/*   Updated: 2022/01/28 23:23:34 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_infos
{
	int				n_philo;	
	int				ttd;
	int				tte;
	int				tts;
	int				max_eat;
	int				die;
	struct s_philo	*philo_ptr;
//	pthread_mutex_t die;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
}					t_infos;

typedef struct s_philo
{
	int				id;
	int				p_max_eat;
	long			last_meal;
	long			time;
	pthread_t		t_id;
	struct s_infos	*info_ptr;
	struct s_philo	*next;
}					t_philo;
#endif
