/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 10:58:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	*start_routine(void *vdata)
{
	routine((t_data *) vdata);
	return (NULL);
}

void	exec_routine(t_data *data)
{
	pthread_t	t;
	pthread_t	guardian;

	if (data->pid != 0)
		return ;
	pthread_mutex_init(&data->start_mutex, NULL);
	pthread_create(&guardian, NULL, &start_guardian, (void *) data);
	pthread_create(&t, NULL, &start_routine, (void *) data);
	pthread_join(t, NULL);
	pthread_join(guardian, NULL);
}
