/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:00:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/03 22:25:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	exit_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

static void	validate_qty(int argc)
{
	if (argc < 4)
		exit_error("too few args");
	if (argc > 5)
		exit_error("too many args");
}

static void	validate_type(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			ft_putstr_fd(argv[i], STDERR_FILENO);
			exit_error(": invalid type");
		}
	}
}

void	validation(int argc, char *argv[])
{
	validate_qty(argc);
	validate_type(argc, argv);
}
