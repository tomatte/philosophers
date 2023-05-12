/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:01:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/12 09:31:01 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	open_semaphore(t_data *data)
{
	sem_t	*semaphore;

	semaphore = sem_open(SEM_FILE, O_CREAT | O_EXCL, 644, data->philo_qty);
	data->semaphore = semaphore;
}

void	fill_data(t_data *data, int argc, char *argv[])
{
	data->philo_qty = ft_atoi(argv[1]);
	data->die_ms = ft_atoi(argv[2]);
	data->eat_ms = ft_atoi(argv[3]);
	data->sleep_ms = ft_atoi(argv[4]);
	open_semaphore(data);
	if (argc >= 6)
		data->eat_times = ft_atoi(argv[5]);
	else
		data->eat_times = -1;
}

/*
	open a named semaphore
	create a semaphore with number of forks (or philos) as initial value
	create number of philos in forks

	in the child process:
		use sem_wait 2 times to get 2 forks
		use sem_post 2 times to put back the 2 forks

	close the semaphore with sem_close
	remove the file with sem_unlink

 */
