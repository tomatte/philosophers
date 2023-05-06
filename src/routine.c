/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 12:07:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
/*
	before start eating (or any action) verify if philosopher is alive
	restart timelapse when start eating
 */

static void	take_forks(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	t_fork	*fork2;
	int		ms;

	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	fork2 = get_node(philo->forks, node->next->index)->content;
	pthread_mutex_lock(&fork1->mutex);
	pthread_mutex_lock(&fork2->mutex);
	ms = get_ms(philo);
	print_msg(ms, philo->num, " has taken a fork\n");
}

static void	put_forks_back(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	t_fork	*fork2;

	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	fork2 = get_node(philo->forks, node->next->index)->content;
	pthread_mutex_unlock(&fork1->mutex);
	pthread_mutex_unlock(&fork2->mutex);
}

static void	eat(t_clst *node, t_philo *philo)
{
	int	ms;

	philo = node->content;
	take_forks(node);
	ms = get_ms(philo);
	print_msg(ms, philo->num, " is eating\n");
	gettimeofday(&philo->start, NULL);
	usleep(philo->data->eat_ms * 1000);
	put_forks_back(node);
}

static void	philo_sleep(t_clst *node, t_philo *philo)
{
	int	ms;

	ms = get_ms(philo);
	print_msg(ms, philo->num, " is sleeping\n");
	usleep(philo->data->sleep_ms * 1000);
}

void	*routine(void *vnode)
{
	t_clst	*node;
	t_philo	*philo;
	int		i;

	node = vnode;
	philo = node->content;
	gettimeofday(&philo->start, NULL);
	i = 0;
	while (i++ < 10)
	{
		eat(node, philo);
		philo_sleep(node, philo);
	}
	return (NULL);
}
