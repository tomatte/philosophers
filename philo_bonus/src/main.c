/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:02:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/12 10:01:46 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	create_childs(t_data *data)
{
	int	*pid;
	int	i;

	i = 0;
	while (i++ < data->philo_qty)
	{
		data->pid = fork();
		if (data->pid == 0)
			return ;
		pid = ft_calloc(1, sizeof(int));
		*pid = data->pid;
		ft_lstadd_back(&data->pid_list, ft_lstnew(pid));
	}
}

static void	open_child_semaphore(t_data *data)
{
	if (data->pid == 0)
	{
		ft_putstr("inside child\n");
	}
	else
		ft_putstr("inside parent\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	create_childs(&data);
	open_child_semaphore(&data);
	while (wait(NULL) != -1);
	sem_close(data.semaphore);
	return 0;
}
