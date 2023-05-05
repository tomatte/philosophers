/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:23:18 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/05 13:23:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_fork	*new_fork(void)
{
	t_fork	*frk;

	frk = ft_calloc(1, sizeof(t_fork));
	frk->owner = 0;
	pthread_mutex_init(&frk->mutex, NULL);
	return (frk);
}

t_clst	*create_forks(t_data *data)
{
	t_clst	*forks;
	int		i;

	forks = NULL;
	i = 0;
	while (i++ < data->philo_qty)
		clst_add_back(&forks, clst_new(new_fork()));
	return (forks);
}
