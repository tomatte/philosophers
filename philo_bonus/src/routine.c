/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:17:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 09:30:11 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	take_forks(t_data *data)
{
	sem_wait(data->semaphore2);
	sem_wait(data->semaphore);
	print_msg(43, data->philo.num, " has taken a fork\n");
	sem_wait(data->semaphore);
	print_msg(43, data->philo.num, " has taken a fork\n");
}

static void	put_forks_back(t_data *data)
{
	sem_post(data->semaphore);
	sem_post(data->semaphore);
	sem_post(data->semaphore2);
}

static void	eat(t_data *data)
{
	print_msg(43, data->philo.num, " is eating\n");
	usleep(data->eat_ms * 1000);
}

static void	philo_eat(t_data *data)
{
	take_forks(data);
	eat(data);
	put_forks_back(data);
}

void	routine(t_data *data)
{
	int	i;

	if (data->pid != 0)
		return ;
	i = 0;
	while (data->eat_times == -1 || i++ < data->eat_times)
	{
		philo_eat(data);
	}
}
