/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:17:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 10:58:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	take_forks(t_data *data)
{
	sem_wait(data->semaphore2);
	sem_wait(data->semaphore);
	ft_putstr("took fork\n");
	sem_wait(data->semaphore);
	ft_putstr("took fork\n");
}

static void	put_forks_back(t_data *data)
{
	ft_putstr("sem post\n");
	sem_post(data->semaphore);
	sem_post(data->semaphore);
	sem_post(data->semaphore2);
}

static void	eat(int ms)
{
	ft_putstr("eating\n");
	usleep(ms * 1000);
}

static void	philo_eat(t_data *data)
{
	take_forks(data);
	eat(data->eat_ms);
	put_forks_back(data);
}

void	routine(t_data *data)
{
	int	i;

	if (data->pid != 0)
		return (ft_putstr("parent returns from routine\n"));
	i = 0;
	while (data->eat_times == -1 || i++ < data->eat_times)
	{
		philo_eat(data);
	}
}
