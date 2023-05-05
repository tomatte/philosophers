/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/05 19:46:57 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "../libft/includes/libftprintf.h"

typedef struct s_clst
{
	void			*content;
	int				index;
	struct s_clst	*next;
	struct s_clst	*prev;
}	t_clst;

typedef struct s_philo
{
	int				num;
	pthread_t		t;
}	t_philo;

typedef struct s_data
{
	int	philo_qty;
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	eat_times;
}	t_data;

typedef struct s_fork
{
	int				owner;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_table
{
	t_data	data;
	t_clst	*philos;
	t_clst	*forks;
}	t_table;

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
t_clst	*create_philos(t_data *data);
t_clst	*create_forks(t_data *data);
void	execute_threads(t_table *table);

//utils
void	action(int ms);
t_philo	*p(t_clst *philos);

//circular linked list
t_clst	*clst_new(void *content);
t_clst	*clst_last(t_clst *lst);
void	clst_add_back(t_clst **lst, t_clst *node);
void	clst_clear(t_clst **lst, void (*del)(void *));
void	clst_iter(t_clst *lst, void (*exec)(t_clst *, void *), void *arg);

#endif
