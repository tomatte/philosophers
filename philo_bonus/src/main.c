/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:02:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/12 10:15:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	create_childs(t_data *data)
{
	pid_t	*pid;
	int		i;

	i = 0;
	while (i++ < data->philo_qty)
	{
		data->pid = fork();
		if (data->pid == 0)
			return ;
		pid = ft_calloc(1, sizeof(pid_t));
		*pid = data->pid;
		ft_lstadd_back(&data->pid_list, ft_lstnew(pid));
	}
}

static void	open_child_semaphore(t_data *data)
{
	if (data->pid == 0)
	{
		open_semaphore(data);
		ft_putstr("opened child semaphore\n");
	}
}

static void	wait_childs(t_data *data)
{
	t_list	*pid_list;
	pid_t	*pid;

	if (data->pid == 0)
		return ;
	pid_list = data->pid_list;
	while (pid_list)
	{
		pid = pid_list->content;
		waitpid(*pid, NULL, WUNTRACED);
		pid_list = pid_list->next;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	create_childs(&data);
	open_child_semaphore(&data);
	wait_childs(&data);
	sem_close(data.semaphore);
	ft_putstr("closed semaphore\n");
	ft_lstclear(&data.pid_list, free);
	return 0;
}
