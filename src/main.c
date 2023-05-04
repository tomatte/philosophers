/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 15:39:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char *argv[])
{
	t_clst	*circular;

	validation(argc, argv);
	circular = clst_new("circulaaaaaaaaar");
	ft_printf("lst: %s\n", (char *) circular->content);
	return (0);
}
