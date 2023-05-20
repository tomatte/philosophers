/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 11:55:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	exec_routine(t_data *data)
{
	static int	dead;

	if (data->pid != 0)
		return ;
	ft_lstclear(&data->pid_list, free);
	dead = 0;
	data->dead = &dead;
	routine(data);
}
