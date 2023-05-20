/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/20 11:16:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_msg(int ms, int num, char *act, t_data *data)
{
	char	msg[MSG_LEN];
	char	*ms_str;
	char	*num_str;

	if (is_dead(data))
		return ;
	ms_str = ft_itoa(ms);
	num_str = ft_itoa(num);
	ft_strlcpy(msg, ms_str, MSG_LEN);
	ft_strlcat(msg, " ", MSG_LEN);
	ft_strlcat(msg, num_str, MSG_LEN);
	ft_strlcat(msg, act, MSG_LEN);
	ft_putstr(msg);
	free(ms_str);
	free(num_str);
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
		exit(1);
	}
	return (0);
}

void	to_sleep(int ms, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < ms)
	{
		usleep(1000);
		if (is_dead(data))
		{
			printf("oi\n");
			return ;
		}
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
