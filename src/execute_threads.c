/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:10:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 09:44:43 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	create_thread(t_clst *node, void *vtable)
{
	t_philo	*philo;

	(void)vtable;
	philo = p(node);
	pthread_create(&philo->t, NULL, routine, node);
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
