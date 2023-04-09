/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:38 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 21:24:57 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *ph_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	printf("[OK] philo created, id : %d\n", data->id);
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;

	left_fork = (data->table->philos[data->id].left_fork);
	right_fork = (data->table->philos[data->id].right_fork);
	int i;
	i = -1;
	while (++i < 1)
	{
		printf("[HI] I'm %d, and My forks are: %p and %p\n", data->id, left_fork, right_fork);
		sleep(1);
	}
	return (NULL);
}
