/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:10:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/05 19:59:33 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*routine(void *vphilo)
{
	t_philo	*philo;

	philo = vphilo;
	sleep(philo->num);
	ft_printf("%d\n", philo->num);
	return (NULL);
}

static void	create_thread(t_clst *node, void *table)
{
	t_philo	*philo;

	philo = p(node);
	pthread_create(&philo->t, NULL, routine, philo);
}

static void	wait_thread(t_clst *node, void *nothing)
{
	t_philo	*philo;

	(void)nothing;
	philo = p(node);
	pthread_join(philo->t, NULL);
}

void	execute_threads(t_table *table)
{
	clst_iter(table->philos, create_thread, (void *) table);
	clst_iter(table->philos, wait_thread, NULL);
}
