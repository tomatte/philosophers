/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:38:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 14:40:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = ((char *) src)[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	char	*s;

	s = (char *) src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	while (i + 1 < size && *s)
	{
		dst[i] = *s;
		s++;
		i++;
	}
	dst[i] = '\0';
	if (dst_len >= size)
		return (size + src_len);
	return (dst_len + src_len);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (s == NULL)
		return ;
	if (fd < 0)
		return ;
	size = sizeof(char) * ft_strlen(s);
	write(fd, s, size);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

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
