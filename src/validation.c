/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:00:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/08 15:04:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

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

static void	validate_philo_qty(char *argv[])
{
	int	philo_qty;

	philo_qty = ft_atoi(argv[1]);
	if (philo_qty <= 1)
		exit_error("too few philos, need at least 2");
}

void	validation(int argc, char *argv[])
{
	validate_arg_qty(argc);
	validate_type(argc, argv);
	validate_philo_qty(argv);
}
