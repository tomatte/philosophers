/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:45:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 22:25:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*p(t_clst *philos)
{
	return ((t_philo *) philos->content);
}

void	action(int ms)
{
	usleep(ms * 1000);
}
