/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:47:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 11:09:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	take_forks(t_data *data)
{
	int	ms;

	sem_wait(data->semaphore2);
	sem_wait(data->semaphore);
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " has taken a fork\n", data);
	sem_wait(data->semaphore);
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " has taken a fork\n", data);
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

	if (is_dead(data))
		return ;
	ms = get_ms(&data->philo);
	pthread_mutex_lock(&data->lastms_mutex);
	data->philo.last_ms = ms;
	pthread_mutex_unlock(&data->lastms_mutex);
	print_msg(ms, data->philo.num, " is eating\n", data);
	to_sleep(data->eat_ms, data);
}

void	philo_eat(t_data *data)
{
	if (is_dead(data))
		return ;
	take_forks(data);
	eat(data);
	put_forks_back(data);
}
