/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:34:53 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 11:01:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	wait_routine(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->start_mutex);
		if (data->started)
		{
			pthread_mutex_unlock(&data->start_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->start_mutex);
		usleep(70);
	}
}

void	*start_guardian(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (data->eat_times == 0)
		return (NULL);
	wait_routine(data);
	return (NULL);
}
