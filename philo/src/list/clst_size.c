/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:00:59 by dbrandao          #+#    #+#             */
/*   Updated: 2023/06/05 15:01:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	clst_size(t_clst *lst)
{
	while (lst->index != 0)
		lst = lst->prev;
	return (lst->prev->index + 1);
}
