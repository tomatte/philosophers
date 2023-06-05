/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/06/05 15:01:35 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# define MSG_LEN 10000

typedef struct s_clst
{
	void			*content;
	int				index;
	struct s_clst	*next;
	struct s_clst	*prev;
}	t_clst;

typedef struct s_data
{
	int				philo_qty;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				eat_times;
	pthread_mutex_t	dead_mutex;
}	t_data;

typedef struct s_philo
{
	int				num;
	int				*dead;
	pthread_t		t;
	t_data			*data;
	t_clst			*forks;
	struct timeval	start;
	struct timeval	end;
	int				started;
	int				last_ms;
	int				ended;
	pthread_mutex_t	ended_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	lastms_mutex;
	pthread_mutex_t	getms_mutex;
	pthread_mutex_t	start_mutex;
}	t_philo;

typedef struct s_fork
{
	int				owner;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_table
{
	t_clst		*philos;
	t_clst		*forks;
	pthread_t	guardian;
}	t_table;

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
t_clst	*create_philos(t_data *data, t_clst *forks);
t_clst	*create_forks(t_data *data);
void	execute_threads(t_table *table);
void	*routine(void *vtable);
void	eat(t_clst *node, t_philo *philo);
void	start_guardian(t_table *table);

//utils
t_philo	*p(t_clst *philos);
void	print_msg(int ms, int num, char *act, t_philo *philo);
int		get_ms(t_philo *philo);
t_clst	*get_node(t_clst *lst, int index);
int		is_dead(t_clst *node);
int		is_dead3(t_philo *philo);

//circular linked list
t_clst	*clst_new(void *content);
t_clst	*clst_last(t_clst *lst);
void	clst_add_back(t_clst **lst, t_clst *node);
void	clst_clear(t_clst **lst, void (*del)(void *));
void	clst_iter(t_clst *lst, void (*exec)(t_clst *));
int		clst_size(t_clst *lst);

//aux
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_isnumber(char *str);
int		ft_isdigit(int c);
int		ft_issign(char c);
int		ft_isspace(char c);

#endif
