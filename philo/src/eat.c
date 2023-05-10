/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:10:16 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/10 10:26:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	put_forks_back(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	t_fork	*fork2;

	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	fork2 = get_node(philo->forks, node->next->index)->content;
	fork1->owner = 0;
	fork2->owner = 0;
	pthread_mutex_unlock(&fork1->mutex);
	pthread_mutex_unlock(&fork2->mutex);
}

int	is_dead(int ms, t_clst *node)
{
	t_philo	*philo;
	int		dead;

	philo = node->content;
	pthread_mutex_lock(&philo->dead_mutex);
	dead = 0;
	if (*philo->dead)
		dead = 1;
	if (ms - philo->last_ms >= philo->data->die_ms)
	{
		print_msg(ms, philo->num, " died\n");
		*philo->dead = 1;
		put_forks_back(node);
		dead = 1;
	}
	pthread_mutex_unlock(&philo->dead_mutex);
	return (dead);
}

static void	take_forks(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	t_fork	*fork2;
	int		ms;

	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	fork2 = get_node(philo->forks, node->next->index)->content;
	if (is_dead2(node))
		return ;
	pthread_mutex_lock(&fork1->mutex);
	pthread_mutex_lock(&fork2->mutex);
	ms = get_ms(philo);
	if (is_dead2(node))
		return ;
	print_msg(ms, philo->num, " has taken a fork\n");
	print_msg(ms, philo->num, " has taken a fork\n");
	fork1->owner = philo->num;
	fork2->owner = philo->num;
}

void	eat(t_clst *node, t_philo *philo)
{
	int	ms;

	philo = node->content;
	if (is_dead2(node))
		return ;
	take_forks(node);
	ms = get_ms(philo);
	if (is_dead2(node))
		return (put_forks_back(node));
	philo->last_ms = ms;
	print_msg(ms, philo->num, " is eating\n");
	usleep(philo->data->eat_ms * 1000);
	put_forks_back(node);
}
