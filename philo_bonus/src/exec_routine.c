/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 12:23:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	take_fork(t_data *data)
{
	int		ms;

	gettimeofday(&data->philo.start, NULL);
	sem_wait(data->semaphore);
	ms = get_ms(&data->philo);
	print_msg(ms, data->philo.num, " has taken a fork\n", data);
	while (1)
		to_sleep(1000, data);
}

void	exec_routine(t_data *data)
{
	static int	dead;

	if (data->pid != 0)
		return ;
	ft_lstclear(&data->pid_list, free);
	dead = 0;
	data->dead = &dead;
	if (data->philo_qty > 1)
		routine(data);
	else
		take_fork(data);
}
