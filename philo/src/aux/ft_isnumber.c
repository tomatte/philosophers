/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:46:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 11:48:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

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
