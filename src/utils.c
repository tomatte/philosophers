/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:45:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 11:28:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*p(t_clst *philos)
{
	return ((t_philo *) philos->content);
}

void	print_msg(int ms, int num, char *act)
{
	char	msg[MSG_LEN];
	char	*ms_str;
	char	*num_str;

	ms_str = ft_itoa(ms);
	num_str = ft_itoa(num);
	ft_strlcpy(msg, ms_str, MSG_LEN);
	ft_strlcat(msg, "ms ", MSG_LEN);
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
