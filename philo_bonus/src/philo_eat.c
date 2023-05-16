/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:47:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 09:59:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	take_forks(t_data *data)
{
	int	ms;

	sem_wait(data->semaphore2);
	sem_wait(data->semaphore);
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " has taken a fork\n");
	sem_wait(data->semaphore);
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " has taken a fork\n");
}

static void	put_forks_back(t_data *data)
{
	sem_post(data->semaphore);
	sem_post(data->semaphore);
	sem_post(data->semaphore2);
}

static void	eat(t_data *data)
{
	int	ms;

	ms = get_ms(&data->philo);
	data->philo.last_ms = ms;
	print_msg(ms, data->philo.num, " is eating\n");
	usleep(data->eat_ms * 1000);
}

void	philo_eat(t_data *data)
{
	take_forks(data);
	eat(data);
	put_forks_back(data);
}