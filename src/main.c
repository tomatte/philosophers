/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/05 11:47:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/* static void	execute_philos(t_all *all)
{
	t_philo	*philo;
	t_clst	*philos;
	t_clst	*aux;

	philos = all->philos;
	philo = p(philos);
	pthread_create(&philo->t, NULL, &philo_routine, (void *) all);
	aux = philos->next;
	while (aux != philos)
	{
		philo= p(aux);
		pthread_create(&philo->t, NULL, &philo_routine, (void *) all);
		aux = aux->next;
	}
} */

int main(int argc, char *argv[])
{
	t_table	table;

	validation(argc, argv);
	fill_data(&table.data, argc, argv);
	table.philos = create_philos(&table.data);
	clst_clear(&table.philos, free);
	return (0);
}

/*
	the philo_routine function will be passed to pthread_create

	it need to receive the list with the philo in the right position

	maybe I should create a struct that receives right philo, left philo
	and the main philo

	struct
	{
		t_philo *main;
		t_philo *left;
		t_philo *right;
		t_data	*data;
	}
	this is probably enough;
 */
