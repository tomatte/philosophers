/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 10:36:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	is_dead3(t_clst *node)
{
	t_philo	*philo;
	int		dead;

	philo = node->content;
	dead = 0;
	if (*philo->dead)
		dead = 1;
	return (dead);
}

static int	is_dead4(int ms, t_clst *node)
{
	t_philo	*philo;
	int		dead;

	philo = node->content;
	dead = 0;
	if (*philo->dead)
		dead = 1;
	if (ms - philo->last_ms >= philo->data->die_ms)
	{
		print_msg(ms, philo->num, " died\n");
		*philo->dead = 1;
		dead = 1;
	}
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
		if (philo->started)
		{
			ms = get_ms(p(philos));
			if (is_dead4(ms, philos))
				break ;
		}
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
