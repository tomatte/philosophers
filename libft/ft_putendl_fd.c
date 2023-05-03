/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:03:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/03 19:32:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	size;

	if (s == NULL)
		return ;
	if (fd < 0)
		return ;
	size = sizeof(char) * ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", sizeof(char));
}
