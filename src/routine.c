/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:53:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 11:27:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
/*
	before start eating (or any action) verify if philosopher is alive
	restart timelapse when start eating
 */

static void	eat(t_clst *node, t_philo *philo)
{
	int	ms;

	philo = node->content;
	gettimeofday(&philo->start, NULL);
	usleep(philo->data->eat_ms * 1000);
	ms = get_ms(philo);
	print_msg(ms, philo->num, "is eating\n");
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
	i = 0;
	while (i++ < 10)
	{
		gettimeofday(&philo->start, NULL);
		eat(node, philo);
		philo_sleep(node, philo);
	}
	return (NULL);
}
