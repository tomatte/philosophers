/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:10:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 15:46:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	create_thread(t_clst *node)
{
	t_philo	*philo;

	philo = p(node);
	pthread_create(&philo->t, NULL, routine, node);
}

static void	wait_thread(t_clst *node)
{
	t_philo	*philo;

	philo = p(node);
	pthread_join(philo->t, NULL);
}

void	execute_threads(t_table *table)
{
	clst_iter(table->philos, create_thread);
	start_guardian(table);
	clst_iter(table->philos, wait_thread);
	pthread_join(table->guardian, NULL);
}
