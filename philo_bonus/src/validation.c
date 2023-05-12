/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:00:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/12 08:08:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	exit_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

static void	validate_arg_qty(int argc)
{
	if (argc < 5)
		exit_error("Too few args");
	if (argc > 6)
		exit_error("Too many args");
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

static void	validate_quantities(int argc, char *argv[])
{
	if (ft_atoi(argv[1]) <= 0)
		exit_error("too few philos, need at least 1");
	if (ft_atoi(argv[2]) < 0)
		exit_error("time to die must to be positive");
	if (ft_atoi(argv[3]) < 0)
		exit_error("time to eat must to be positive");
	if (ft_atoi(argv[4]) < 0)
		exit_error("time to sleep must to be positive");
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		exit_error("number of times to eat must to be positive");
}

void	validation(int argc, char *argv[])
{
	validate_arg_qty(argc);
	validate_type(argc, argv);
	validate_quantities(argc, argv);
}
