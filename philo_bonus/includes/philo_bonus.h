/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:47:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 15:06:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>

# define SEM_FILE "/semaphore1"
# define SEM_FILE2 "/semaphore2"
# define MSG_LEN 10000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_philo
{
	int				num;
	int				*dead;
	struct timeval	start;
	struct timeval	end;
	int				last_ms;
}	t_philo;

typedef struct s_data
{
	int				philo_qty;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				eat_times;
	pid_t			pid;
	t_list			*pid_list;
	sem_t			*semaphore;
	sem_t			*semaphore2;
	t_philo			philo;
	int				started;
	pthread_mutex_t	start_mutex;
	int				*dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	lastms_mutex;
}	t_data;

void	validation(int argc, char *argv[]);
void	fill_data(t_data *data, int argc, char *argv[]);
void	open_semaphore(t_data *data);
void	routine(t_data *data);
void	finalize(t_data *data);
void	philo_eat(t_data *data);
void	exec_routine(t_data *data);
void	*start_guardian(void *vdata);

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
char	*ft_isnumber(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

//lst
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//utils
void	print_msg(int ms, int num, char *act, t_data *data);
int		get_ms(t_philo *philo);
int		is_dead(t_data *data);
int		is_dead2(t_data *data);
void	kill_childs(t_data *data);

#endif
