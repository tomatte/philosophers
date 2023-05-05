/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:03:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 21:53:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/* static void	philo_eat(t_clst *philos, t_data *data)
{

} */

void	philo_routine(t_clst *philos, t_data *data)
{
	(void)data;

	t_clst	*aux;
	ft_printf("num: %d\n", p(philos)->num);
	aux = philos->next;
	while (aux != philos)
	{
		ft_printf("num: %d\n", p(aux)->num);
		aux = aux->next;
	}
	//eat
	//sleep
	//think
}

/*
	loop
		eat -> put forks back
		sleep
		think
	obs: only eating need a mutex for forks
 */
