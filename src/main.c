/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/05/04 13:38:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_mutex_t	mutex;

void	*routine1(void *s)
{
	int	i;

	i = 0;
	while (i++ < 30000)
	{
		pthread_mutex_lock(&mutex);
		ft_printf("_");
		pthread_mutex_unlock(&mutex);
	}
	(void)s;
	return (NULL);
}

void	*routine2(void *s)
{
	int	i;

	i = 0;
	while (i++ < 30000)
	{
		pthread_mutex_lock(&mutex);
		ft_printf("|");
		pthread_mutex_unlock(&mutex);
	}
	(void)s;
	return (NULL);
}

static void	execute_thread(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine1, NULL);
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

int main(int argc, char *argv[])
{
	struct timeval	start;
	struct timeval	end;
	int				mtime;

	pthread_mutex_init(&mutex, NULL);
	validation(argc, argv);
	gettimeofday(&start, NULL);
	execute_thread();
	gettimeofday(&end, NULL);
	mtime = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
	ft_printf("time: %d\n", mtime);
	return (0);
}


/*



 */
