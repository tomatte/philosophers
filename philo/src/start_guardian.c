/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_guardian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 14:30:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*guard_threads(void *vphilos)
{
	t_clst	*philos;

	philos = vphilos;
	while (1)
	{
		if (is_dead(philos))
			break ;
		philos = philos->next;
	}
	return (NULL);
}

void	start_guardian(t_table *table)
{
	void	*vphilos;

	vphilos = (void *) table->philos;
	pthread_create(&table->guardian, NULL, guard_threads, vphilos);
}
