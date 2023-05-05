/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 21:51:54 by dbrandao         ###   ########.fr       */
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
	struct s_clst	*next;
	struct s_clst	*prev;
}	t_clst;

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	left_mutex;
	pthread_mutex_t	right_mutex;
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

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
t_clst	*create_philos(t_data *data);
t_philo	*p(t_clst *philos);
void	philo_routine(t_clst *philos, t_data *data);

//circular linked list
t_clst	*clst_new(void *content);
t_clst	*clst_last(t_clst *lst);
void	clst_add_back(t_clst **lst, t_clst *node);
void	clst_clear(t_clst **lst, void (*del)(void *));

#endif
