/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:41:56 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	pass_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static int	is_number(char *str)
{
	if (!str)
		return (0);
	if (ft_issign(*str))
		str++;
	if (!*str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (!ft_isspace(*str) && *str != '\0')
		return (0);
	return (1);
}

char	*ft_isnumber(char *str)
{
	if (!str || !*str)
		return (NULL);
	pass_spaces(&str);
	if (!ft_isdigit(*str) && !ft_issign(*str))
		return (NULL);
	if (is_number(str))
		return (str);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < (int) n)
	{
		((char *) s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!nmemb || !size)
		return (NULL);
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
