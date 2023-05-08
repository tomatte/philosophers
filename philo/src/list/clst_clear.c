/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:09:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 16:38:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	clst_del_one(t_clst *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	if (del)
		del(node->content);
	free(node);
}

void	clst_clear(t_clst **lst, void (*del)(void *))
{
	t_clst	*pass;
	t_clst	*aux;

	if (lst == NULL || *lst == NULL)
		return ;
	pass = (*lst)->next;
	while (pass != *lst)
	{
		aux = pass;
		pass = pass->next;
		clst_del_one(aux, del);
	}
	clst_del_one(*lst, del);
	*lst = NULL;
}
