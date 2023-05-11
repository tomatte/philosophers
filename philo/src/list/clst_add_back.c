/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:41:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/11 19:34:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	clst_add_back(t_clst **lst, t_clst *node)
{
	t_clst	*aux;

	if (node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		node->index = 0;
		return ;
	}
	aux = clst_last(*lst);
	node->prev = aux;
	node->next = *lst;
	aux->next = node;
	(*lst)->prev = node;
	node->index = node->prev->index + 1;
}
