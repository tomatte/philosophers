/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/10 10:37:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	philo_sleep(t_clst *node)
{
	t_philo	*philo;
	int		ms;

	philo = node->content;
	if (is_dead2(node))
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
	if (is_dead2(node))
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
	pthread_mutex_lock(&philo->started_mutex);
	philo->started = 1;
	pthread_mutex_unlock(&philo->started_mutex);
	i = 0;
	while (times_to_eat == -1 || i++ < times_to_eat)
	{
		eat(node, philo);
		philo_sleep(node);
		philo_think(node);
		if (is_dead2(node))
			break ;
	}
	return (NULL);
}
