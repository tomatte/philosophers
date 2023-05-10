/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/10 10:21:41 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_dead3(t_clst *node)
{
	t_philo	*philo;
	int		dead;

	philo = node->content;
	pthread_mutex_lock(&philo->dead_mutex);
	dead = 0;
	if (*philo->dead)
		dead = 1;
	pthread_mutex_unlock(&philo->dead_mutex);
	return (dead);
}

static void	*guard_threads(void *vphilos)
{
	t_clst	*philos;
	t_philo	*philo;
	int		ms;

	philos = vphilos;
	while (1)
	{
		philo = philos->content;
		if (is_dead3(philos))
			break ;
		if (philo->started)
		{
			ms = get_ms(p(philos));
			is_dead(ms, philos);
			philos = philos->next;
		}
	}
	return (NULL);
}

void	start_guardian(t_table *table)
{
	void	*vphilos;

	vphilos = (void *) table->philos;
	pthread_create(&table->guardian, NULL, guard_threads, vphilos);
}
