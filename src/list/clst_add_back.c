/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:41:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 15:56:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	clst_add_back(t_clst **lst, t_clst *node)
{
	t_clst	*aux;

	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	aux = clst_last(*lst);
	node->prev = aux;
	node->next = *lst;
	aux->next = node;
	(*lst)->prev = node;
}

/*

3 <- 1 -> 2
1 <- 2 -> 3
2 <- 3 -> 1

4 <- 1 -> 2
1 <- 2 -> 3
2 <- 3 -> 4
3 <- 4 -> 1

node-prev = ex-ultimo
node->next = primeiro
ex-ultimo->next = node
primeiro->prev = node
 */
