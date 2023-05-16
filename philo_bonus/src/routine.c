/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:17:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 09:47:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	routine(t_data *data)
{
	int	i;

	if (data->pid != 0)
		return ;
	gettimeofday(&data->philo.start, NULL);
	i = 0;
	while (data->eat_times == -1 || i++ < data->eat_times)
	{
		philo_eat(data);
	}
}
