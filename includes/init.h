#ifndef INIT_H
# define INIT_H
# include "struct.h"
# include "libft.h"

int		parsing(int ac, char **av);
t_infos	*fill_info(int ac, char **av);
t_philo	*fill_philo(t_infos *infos);

#endif
