/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/06/05 10:09:33 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	clst_size(t_clst *lst)
{
	while (lst->index != 0)
		lst = lst->prev;
	return (lst->prev->index + 1);
}

static int	ended_philo(t_philo *philo)
{
	int	ended;

	pthread_mutex_lock(&philo->ended_mutex);
	ended = philo->ended;
	pthread_mutex_unlock(&philo->ended_mutex);
	return (ended);
}

static int	ended_all(t_clst *lst)
{
	int	ended;

	ended = 0;
	while (lst->index != 0)
		lst = lst->prev;
	if (p(lst)->ended)
		ended++;
	lst = lst->next;
	while (lst->index != 0)
	{
		if (p(lst)->ended)
			ended++;
		lst = lst->next;
	}
	if (ended >= clst_size(lst))
		return (1);
	return (0);
}

static void	*guard_threads(void *vphilos)
{
	t_clst	*philos;
	t_philo	*philo;

	philos = vphilos;
	philo = philos->content;
	if (philo->data->eat_times == 0)
		return (NULL);
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
		if (ended_all(philos))
			break ;
		if (ended_philo(philo))
			continue ;
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
