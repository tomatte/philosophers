/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 10:28:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
/*
	before start eating (or any action) verify if philosopher is alive
	restart timelapse when start eating
 */

static int	get_ms(t_philo *philo)
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

static void	eat(t_clst *node, t_philo *philo)
{
	int	ms;

	philo = node->content;
	sleep(node->index);
	ms = get_ms(philo);
	ft_printf("%d finished eating at %d\n", node->index, ms);
}

void	*routine(void *vnode)
{
	t_clst	*node;
	t_philo	*philo;

	node = vnode;
	philo = node->content;
	gettimeofday(&philo->start, NULL);
	eat(node, philo);
	return (NULL);
}
