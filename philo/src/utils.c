/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:45:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 18:04:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*p(t_clst *philos)
{
	return ((t_philo *) philos->content);
}

int	get_ms(t_philo *philo)
{
	int	seconds;
	int	microseconds;
	int	ms;

	pthread_mutex_lock(&philo->getms_mutex);
	gettimeofday(&philo->end, NULL);
	seconds = (philo->end.tv_sec - philo->start.tv_sec);
	microseconds = (philo->end.tv_usec - philo->start.tv_usec);
	pthread_mutex_unlock(&philo->getms_mutex);
	ms = seconds * 1000 + microseconds / 1000;
	return (ms);
}

t_clst	*get_node(t_clst *lst, int index)
{
	t_clst	*pass;

	if (lst == NULL || index < 0)
		return (NULL);
	if (lst->index == index)
		return (lst);
	pass = lst->next;
	while (pass != lst)
	{
		if (pass->index == index)
			return (pass);
		pass = pass->next;
	}
	return (NULL);
}

int	is_dead(t_clst *node)
{
	t_philo	*philo;
	int		dead;
	int		ms;
	int		philo_ms;

	philo = node->content;
	dead = 0;
	if (is_dead3(philo))
		return (1);
	ms = get_ms(philo);
	pthread_mutex_lock(&philo->getms_mutex);
	philo_ms = ms - philo->last_ms;
	pthread_mutex_unlock(&philo->getms_mutex);
	if (philo_ms >= philo->data->die_ms)
	{
		print_msg(ms, philo->num, " died\n", philo);
		pthread_mutex_lock(philo->dead_mutex);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_mutex);
		dead = 1;
	}
	return (dead);
}

void	print_msg(int ms, int num, char *act, t_philo *philo)
{
	char	msg[MSG_LEN];
	char	*ms_str;
	char	*num_str;

	if (is_dead3(philo))
		return ;
	ms_str = ft_itoa(ms);
	num_str = ft_itoa(num);
	ft_strlcpy(msg, ms_str, MSG_LEN);
	ft_strlcat(msg, " ", MSG_LEN);
	ft_strlcat(msg, num_str, MSG_LEN);
	ft_strlcat(msg, act, MSG_LEN);
	ft_putstr(msg);
	free(ms_str);
	free(num_str);
}
