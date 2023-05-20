/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:28:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 11:14:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	finalize(t_data *data)
{
	sem_close(data->semaphore);
	sem_close(data->semaphore2);
	sem_unlink(SEM_FILE);
	sem_unlink(SEM_FILE2);
	ft_lstclear(&data->pid_list, free);
}
