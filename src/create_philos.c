/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:55:38 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 18:10:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_clst	*new_philo(int num)
{
	t_clst		*node;
	t_philo		*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	philo->left_fork = 1;
	philo->right_fork = 0;
	philo->num = num;
	node = clst_new(philo);
	return (node);
}

t_clst	*create_philos(t_data *data)
{
	t_clst	*philos;
	int		i;

	philos = NULL;
	i = 0;
	while (++i <= data->philo_qty)
		clst_add_back(&philos, new_philo(i));
	return (philos);
}
