/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 16:37:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char *argv[])
{
	t_clst	*circular;

	validation(argc, argv);
	circular = clst_new(ft_strdup("essa porra"));
	clst_add_back(&circular, clst_new(ft_strdup("aveia")));
	clst_add_back(&circular, clst_new(ft_strdup("pipoca")));
	ft_printf("lst: %s\n", (char *) circular->content);
	ft_printf("lst: %s\n", (char *) circular->next->content);
	ft_printf("lst: %s\n", (char *) circular->next->next->content);
	ft_printf("lst: %s\n", (char *) clst_last(circular)->content);
	clst_clear(&circular, free);
	clst_clear(NULL, free);
	t_clst	*eba = clst_new(ft_strdup("vumbora"));
	clst_clear(&eba, free);
	return (0);
}
