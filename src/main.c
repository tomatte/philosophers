/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 16:07:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char *argv[])
{
	t_clst	*circular;

	validation(argc, argv);
	circular = clst_new("circulaaaaaaaaar");
	clst_add_back(&circular, clst_new("aveia"));
	clst_add_back(&circular, clst_new("pipoca"));
	ft_printf("lst: %s\n", (char *) circular->content);
	ft_printf("lst: %s\n", (char *) circular->next->content);
	ft_printf("lst: %s\n", (char *) circular->next->next->content);
	ft_printf("lst: %s\n", (char *) clst_last(circular)->content);
	return (0);
}
