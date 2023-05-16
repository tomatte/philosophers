/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:02:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/16 10:17:31 by dbrandao         ###   ########.fr       */
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
		data->philo.num = i;
		if (data->pid == 0)
			return ;
		pid = ft_calloc(1, sizeof(pid_t));
		*pid = data->pid;
		ft_lstadd_back(&data->pid_list, ft_lstnew(pid));
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

static void	open_parent_semaphore(t_data *data)
{
	sem_t	*sem1;
	sem_t	*sem2;

	sem_unlink(SEM_FILE);
	sem_unlink(SEM_FILE2);
	sem1 = sem_open(SEM_FILE, O_CREAT, 0644, data->philo_qty);
	sem2 = sem_open(SEM_FILE2, O_CREAT, 0644, data->philo_qty / 2);
	data->semaphore = sem1;
	data->semaphore2 = sem2;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	validation(argc, argv);
	fill_data(&data, argc, argv);
	open_parent_semaphore(&data);
	create_childs(&data);
	exec_routine(&data);
	wait_childs(&data);
	finalize(&data);
	return 0;
}
