/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:17:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 11:18:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	philo_started(t_data *data)
{
	pthread_mutex_lock(&data->start_mutex);
	data->started = 1;
	pthread_mutex_unlock(&data->start_mutex);
}

static void	philo_sleep(t_data *data)
{
	int		ms;

	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " is sleeping\n");
	usleep(data->sleep_ms * 1000);
}

static void	philo_think(t_data *data)
{
	int		ms;

	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " is thinking\n");
}

void	routine(t_data *data)
{
	int	i;

	gettimeofday(&data->philo.start, NULL);
	philo_started(data);
	i = 0;
	while (data->eat_times == -1 || i++ < data->eat_times)
	{
		if (is_dead2(data))
			return (ft_putstr("philo exited\n"));
		philo_eat(data);
		philo_sleep(data);
		philo_think(data);
	}
}
