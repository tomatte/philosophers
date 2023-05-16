/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 11:27:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_msg(int ms, int num, char *act, t_data *data)
{
	char	msg[MSG_LEN];
	char	*ms_str;
	char	*num_str;

	if (is_dead2(data))
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

	ms = get_ms(&data->philo);
	philo_ms = ms - data->philo.last_ms;
	if (philo_ms >= data->die_ms)
	{
		print_msg(ms, data->philo.num, " died\n", data);
		return (1);
	}
	return (0);
}

int	is_dead2(t_data *data)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(&data->dead_mutex);
	if (*(data->dead))
		dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	return (dead);
}
