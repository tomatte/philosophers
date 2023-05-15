/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 11:27:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	clear_table(t_table *table)
{
	clst_clear(&table->philos, free);
	clst_clear(&table->forks, free);
}

int	main(int argc, char *argv[])
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
