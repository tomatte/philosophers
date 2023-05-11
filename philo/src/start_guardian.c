/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 11:09:50 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_dead2(t_clst *node)
{
	t_philo	*philo;
	int		dead;

	philo = node->content;
	dead = 0;
	pthread_mutex_lock(&philo->started_mutex);
	if (philo->started && is_dead(node))
		dead = 1;
	pthread_mutex_unlock(&philo->started_mutex);
	return (dead);
}

static void	*guard_threads(void *vphilos)
{
	t_clst	*philos;

	philos = vphilos;
	while (1)
	{
		if (is_dead2(philos))
			break ;
		philos = philos->next;
	}
	return (NULL);
}

void	start_guardian(t_table *table)
{
	void	*vphilos;

	vphilos = (void *) table->philos;
	pthread_create(&table->guardian, NULL, guard_threads, vphilos);
}
