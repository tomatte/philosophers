#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include "../libft/includes/libftprintf.h"

# define SEM_FILE ".semaphore"

typedef struct s_data
{
	int		philo_qty;
	int		die_ms;
	int		eat_ms;
	int		sleep_ms;
	int		eat_times;
	sem_t	*semaphore;
}	t_data;

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
void	open_semaphore(t_data *data);

#endif
