/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:38 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/05/06 17:15:06 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *ph_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (!data->table->is_anybody_died)
	{
		ph_eat(data);
		ph_sleep(data);
		ph_think(data);
	}
	return (NULL);
}

void ph_eat(t_data *data)
{
	long long cr;

	pthread_mutex_lock(data->table->philos[data->id].left_fork);
	pthread_mutex_lock(data->table->philos[data->id].right_fork);
	cr = ph_updateTime(data->table);
	ph_print("is eating", data);
	// printf("[%lld]\t%d eating with these forks %p & %p\n", ph_updateTime(data->table) - data->table->start_milis, data->id, data->table->philos[data->id].left_fork, data->table->philos[data->id].left_fork);
	while (cr + data->table->tte > ph_updateTime(data->table))
		continue;
	pthread_mutex_unlock(data->table->philos[data->id].left_fork);
	pthread_mutex_unlock(data->table->philos[data->id].right_fork);
}

void ph_sleep(t_data *data)
{
	long cr;

	cr = ph_updateTime(data->table);
	ph_print("is sleeping", data);
	while (cr + data->table->tte > ph_updateTime(data->table))
		continue;
}

void ph_think(t_data *data)
{
	ph_print("is thinking", data);
}

void ph_print(char *str, t_data *data)
{
	if (1) // mutex check
		printf("[%lld]\t%d %s\n", ph_updateTime(data->table) - data->table->start_milis, data->id, str);
}
