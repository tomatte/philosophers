/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:31:35 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/15 11:45:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *) malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	decimals_count(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	powerr(int n, int pwr)
{
	int	result;

	result = 1;
	while (pwr--)
		result *= n;
	return (result);
}

static char	*alloc_and_values(int *n, int *i, int *dec)
{
	char	*number;

	if (!*n)
		*dec = 1;
	else
		*dec = decimals_count(*n);
	if (*n >= 0)
	{
		number = (char *) malloc(*dec + 1);
		if (!number)
			return (NULL);
		*i = 0;
	}
	else
	{
		number = (char *) malloc(*dec + 2);
		if (!number)
			return (NULL);
		*number = '-';
		*n *= -1;
		*i = 1;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	int		dec;
	int		i;
	int		aux;
	char	*number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = alloc_and_values(&n, &i, &dec);
	if (!number)
		return (NULL);
	while (dec)
	{
		aux = n / powerr(10, dec - 1);
		number[i] = aux + 48;
		n -= aux * powerr(10, dec - 1);
		dec--;
		while (dec - decimals_count(n) > 0)
		{
			number[++i] = '0';
			dec--;
		}
		i++;
	}
	number[i] = '\0';
	return (number);
}
