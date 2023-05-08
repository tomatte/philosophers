/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:38:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/06 09:47:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	clst_iter(t_clst *lst, void (*exec)(t_clst *))
{
	t_clst	*pass;

	exec(lst);
	pass = lst->next;
	while (pass != lst)
	{
		exec(pass);
		pass = pass->next;
	}
}
