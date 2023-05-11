/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:45:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 10:36:23 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*p(t_clst *philos)
{
	return ((t_philo *) philos->content);
}

void	print_msg(int ms, int num, char *act)
{
	char	msg[MSG_LEN];
	char	*ms_str;
	char	*num_str;

	ms_str = ft_itoa(ms);
	num_str = ft_itoa(num);
	ft_strlcpy(msg, ms_str, MSG_LEN);
	ft_strlcat(msg, "ms ", MSG_LEN);
	ft_strlcat(msg, num_str, MSG_LEN);
	ft_strlcat(msg, act, MSG_LEN);
	ft_putstr(msg);
	free(ms_str);
	free(num_str);
}

int	get_ms(t_philo *philo)
{
	int	seconds;
	int	microseconds;
	int	ms;

	gettimeofday(&philo->end, NULL);
	seconds = (philo->end.tv_sec - philo->start.tv_sec);
	microseconds = (philo->end.tv_usec - philo->start.tv_usec);
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

int	is_dead2(t_clst *node)
{
	t_philo	*philo;
	int		dead;
	int		ms;

	philo = node->content;
	ms = get_ms(philo);
	dead = 0;
	if (*philo->dead)
		dead = 1;
	else if (ms - philo->last_ms >= philo->data->die_ms)
	{
		print_msg(ms, philo->num, " died\n");
		*philo->dead = 1;
		dead = 1;
	}
	return (dead);
}
