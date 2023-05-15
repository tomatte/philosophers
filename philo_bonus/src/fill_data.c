/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:01:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 10:55:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	open_semaphore(t_data *data)
{
	sem_t	*semaphore;
	sem_t	*semaphore2;

	semaphore = sem_open(SEM_FILE, O_CREAT, 0644, data->philo_qty);
	semaphore2 = sem_open(SEM_FILE2, O_CREAT, 0644, data->philo_qty / 2);
	if (semaphore == SEM_FAILED || semaphore2 == SEM_FAILED)
		ft_putstr("sem failed to open\n");
	data->semaphore = semaphore;
	data->semaphore2 = semaphore2;
}

void	fill_data(t_data *data, int argc, char *argv[])
{
	data->philo_qty = ft_atoi(argv[1]);
	data->die_ms = ft_atoi(argv[2]);
	data->eat_ms = ft_atoi(argv[3]);
	data->sleep_ms = ft_atoi(argv[4]);
	data->pid_list = NULL;
	data->pid = -1;
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
