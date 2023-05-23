/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/23 10:27:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_msg(int ms, int num, char *act, t_data *data)
{
	if (is_dead(data))
		return ;
	printf("%d %d%s", ms, num, act);
}

int	get_ms(t_philo *philo)
{
	int	seconds;
	int	microseconds;
	int	ms;

	gettimeofday(&philo->end, NULL);
	seconds = (philo->end.tv_sec - philo->start.tv_sec);
	microseconds = (philo->end.tv_usec - philo->start.tv_usec);
	ms = seconds * 1000 + microseconds / 1000;
	return (ms);
}

int	is_dead(t_data *data)
{
	int	ms;
	int	philo_ms;

	if (*(data->dead))
		return (1);
	ms = get_ms(&data->philo);
	philo_ms = ms - data->philo.last_ms;
	if (philo_ms >= data->die_ms)
	{
		*(data->dead) = 1;
		printf("%d %d died\n", ms, data->philo.num);
		finalize(data);
		exit(1);
	}
	return (0);
}

void	to_sleep(int ms, t_data *data)
{
	int	rate;

	rate = 4;
	while (ms >= rate)
	{
		usleep(1000 * rate);
		if (is_dead(data))
			return ;
		ms -= rate;
	}
	while (ms--)
	{
		usleep(1000);
		if (is_dead(data))
			return ;
	}
}

void	kill_childs(t_data *data)
{
	static int	executed = 0;
	t_list		*pid_list;
	pid_t		*pid;

	if (executed == 0)
		executed = 1;
	else
		return ;
	pid_list = data->pid_list;
	while (pid_list)
	{
		pid = pid_list->content;
		kill(*pid, SIGKILL);
		pid_list = pid_list->next;
	}
}
