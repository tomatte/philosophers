/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 15:46:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	clear_table(t_table *table)
{
	clst_clear(&table->philos, free);
	clst_clear(&table->forks, free);
}

void	print_num(t_clst *lst)
{
	ft_printf("num: %d\n", p(lst)->num);
}

int main(int argc, char *argv[])
{
	t_table	table;
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	table.forks = create_forks(&data);
	table.philos = create_philos(&data, table.forks);
	execute_threads(&table);
	clear_table(&table);
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
