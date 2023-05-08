/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/08 14:41:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	philo_sleep(t_clst *node, t_philo *philo)
{
	int	ms;

	if (*philo->dead)
		return ;
	ms = get_ms(philo);
	print_msg(ms, philo->num, " is sleeping\n");
	usleep(philo->data->sleep_ms * 1000);
}

static void	philo_think(t_clst *node)
{
	t_philo	*philo;
	int		ms;

	philo = node->content;
	if (*philo->dead)
		return ;
	ms = get_ms(philo);
	print_msg(ms, philo->num, " is thinking\n");
}

void	*routine(void *vnode)
{
	t_clst	*node;
	t_philo	*philo;
	int		times_to_eat;
	int		i;

	node = vnode;
	philo = node->content;
	times_to_eat = philo->data->eat_times;
	gettimeofday(&philo->start, NULL);
	i = 0;
	while (times_to_eat == -1 || i++ < times_to_eat)
	{
		eat(node, philo);
		philo_sleep(node, philo);
		philo_think(node);
		if (*philo->dead)
			break ;
	}
	return (NULL);
}
