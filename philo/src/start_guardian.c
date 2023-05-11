/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 16:43:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*guard_threads(void *vphilos)
{
	t_clst	*philos;
	t_philo	*philo;

	philos = vphilos;
	philo = philos->content;
	while (1)
	{
		pthread_mutex_lock(&philo->start_mutex);
		if (philo->started)
			break ;
		pthread_mutex_unlock(&philo->start_mutex);
		usleep(50);
	}
	pthread_mutex_unlock(&philo->start_mutex);
	while (1)
	{
		if (is_dead(philos))
			break ;
		philos = philos->next;
		usleep(100);
	}
	return (NULL);
}

void	start_guardian(t_table *table)
{
	void	*vphilos;

	vphilos = (void *) table->philos;
	pthread_create(&table->guardian, NULL, guard_threads, vphilos);
}
