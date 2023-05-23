/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:17:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 11:14:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	philo_sleep(t_data *data)
{
	int		ms;

	if (is_dead(data))
		return ;
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " is sleeping\n", data);
	to_sleep(data->sleep_ms, data);
}

static void	philo_think(t_data *data)
{
	int		ms;

	if (is_dead(data))
		return ;
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " is thinking\n", data);
}

void	routine(t_data *data)
{
	int	i;

	gettimeofday(&data->philo.start, NULL);
	i = 0;
	while (data->eat_times == -1 || i++ < data->eat_times)
	{
		if (is_dead(data))
			return ;
		philo_eat(data);
		philo_sleep(data);
		philo_think(data);
	}
}
