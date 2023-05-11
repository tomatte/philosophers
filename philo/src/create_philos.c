/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:55:38 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 16:02:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_clst	*new_philo(int num, t_data *data, t_clst *forks, int *dead)
{
	t_clst		*node;
	t_philo		*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	ft_bzero(philo, sizeof(t_philo));
	pthread_mutex_init(&philo->lastms_mutex, NULL);
	pthread_mutex_init(&philo->getms_mutex, NULL);
	philo->dead_mutex = &data->dead_mutex;
	philo->num = num;
	philo->data = data;
	philo->forks = forks;
	philo->dead = dead;
	node = clst_new(philo);
	return (node);
}

t_clst	*create_philos(t_data *data, t_clst *forks)
{
	static int	dead = 0;
	t_clst		*philos;
	int			i;

	philos = NULL;
	i = 0;
	while (++i <= data->philo_qty)
		clst_add_back(&philos, new_philo(i, data, forks, &dead));
	return (philos);
}
