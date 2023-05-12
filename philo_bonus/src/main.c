/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:02:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/12 09:36:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	sem_close(data.semaphore);
	return 0;
}
