/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	philo_sleep(t_clst *node)
{
	t_philo	*philo;
	int		ms;

	philo = node->content;
	ms = get_ms(philo);
	print_msg(ms, philo->num, " is sleeping\n", philo);
	usleep(philo->data->sleep_ms * 1000);
}

static void	philo_think(t_clst *node)
{
	t_philo	*philo;
	int		ms;

	philo = node->content;
	ms = get_ms(philo);
	print_msg(ms, philo->num, " is thinking\n", philo);
}

int	is_dead3(t_philo *philo)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(philo->dead_mutex);
	if (*philo->dead)
		dead = 1;
	pthread_mutex_unlock(philo->dead_mutex);
	return (dead);
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
	pthread_mutex_lock(&philo->getms_mutex);
	gettimeofday(&philo->start, NULL);
	pthread_mutex_unlock(&philo->getms_mutex);
	i = 0;
	while (times_to_eat == -1 || i++ < times_to_eat)
	{
		eat(node, philo);
		philo_sleep(node);
		philo_think(node);
		if (is_dead3(philo))
			break ;
	}
	return (NULL);
}
