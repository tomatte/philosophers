/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:10:16 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 18:59:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	put_forks_back(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	t_fork	*fork2;

	if (node->next == node && node->next->next == node)
		return ;
	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	fork2 = get_node(philo->forks, node->next->index)->content;
	fork1->owner = 0;
	fork2->owner = 0;
	pthread_mutex_unlock(&fork1->mutex);
	pthread_mutex_unlock(&fork2->mutex);
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
	if (node->next->index == 0)
	{
		pthread_mutex_lock(&fork2->mutex);
		pthread_mutex_lock(&fork1->mutex);
	}
	else
	{
		pthread_mutex_lock(&fork1->mutex);
		pthread_mutex_lock(&fork2->mutex);
	}
	ms = get_ms(philo);
	print_msg(ms, philo->num, " has taken a fork\n", philo);
	print_msg(ms, philo->num, " has taken a fork\n", philo);
	fork1->owner = philo->num;
	fork2->owner = philo->num;
}

static void	take_fork(t_clst *node)
{
	t_philo *philo;
	t_fork	*fork1;
	int		ms;

	philo = node->content;
	fork1 = get_node(philo->forks, node->index)->content;
	pthread_mutex_lock(&fork1->mutex);
	fork1->owner = philo->num;
	ms = get_ms(philo);
	print_msg(ms, philo->num, " has taken a fork\n", philo);
	while (!is_dead3(philo))
		usleep(50);
	fork1->owner = 0;
	pthread_mutex_unlock(&fork1->mutex);
}

static void	take_the_forks(t_clst *node)
{
	if (node->next == node && node->next->next == node)
		take_fork(node);
	else
		take_forks(node);
}

void	eat(t_clst *node, t_philo *philo)
{
	int	ms;

	philo = node->content;
	take_the_forks(node);
	ms = get_ms(philo);
	pthread_mutex_lock(&philo->lastms_mutex);
	philo->last_ms = ms;
	pthread_mutex_unlock(&philo->lastms_mutex);
	print_msg(ms, philo->num, " is eating\n", philo);
	usleep(philo->data->eat_ms * 1000);
	put_forks_back(node);
}
