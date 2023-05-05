/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:55:38 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 21:49:22 by dbrandao         ###   ########.fr       */
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
	pthread_mutex_init(&philo->left_mutex, NULL);
	node = clst_new(philo);
	return (node);
}

static void	asign_right_mutex(t_clst *philos)
{
	t_clst	*aux;

	if (philos == NULL)
		return ;
	aux = philos->next;
	while (aux != philos)
	{
		p(aux)->right_mutex = p(aux->next)->left_mutex;
		aux = aux->next;
	}
	p(philos)->right_mutex = p(philos->next)->left_mutex;
}

t_clst	*create_philos(t_data *data)
{
	t_clst	*philos;
	int		i;

	philos = NULL;
	i = 0;
	while (++i <= data->philo_qty)
		clst_add_back(&philos, new_philo(i));
	asign_right_mutex(philos);
	return (philos);
}

/*
	left
	mutex1

	left
	mutex1

 	left
	mutex1
 */
