/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:35 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 16:05:35 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_clst	*clst_new(void *content)
{
	t_clst	*node;

	node = ft_calloc(1, sizeof(t_clst));
	node->next = node;
	node->prev = node;
	node->content = content;
	return (node);
}
