/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 17:48:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char *argv[])
{
	//t_clst	*philos;
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	ft_printf("%d%d%d%d%d\n", data.die_ms, data.eat_ms, data.philo_qty, data.sleep_ms, data.eat_times);
	return (0);
}
