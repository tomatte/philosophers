#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "../libft/includes/libftprintf.h"

# define SEM_FILE "/semaphore1"
# define SEM_FILE2 "/semaphore2"

typedef struct s_data
{
	int		philo_qty;
	int		die_ms;
	int		eat_ms;
	int		sleep_ms;
	int		eat_times;
	pid_t	pid;
	t_list	*pid_list;
	sem_t	*semaphore;
	sem_t	*semaphore2;
}	t_data;

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
void	open_semaphore(t_data *data);
void	routine(t_data *data);
void	finalize(t_data *data);

#endif
