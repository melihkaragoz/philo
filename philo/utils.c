/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:38 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/05/08 22:00:57 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *ph_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	data->table->philos[data->id].id = data->id;
	data->table->philos[data->id].data = data;
	// lock(data->table->dmx);
	while (!data->table->is_anybody_died && !data->table->count_ok)
	{
		if (!data->table->pme || data->table->philos[data->id].eat_count < data->table->pme)
			ph_eat(data);
		ph_sleep(data);
		ph_think(data);
	}
	// unlock(data->table->dmx);
	return (NULL);
}

void ph_eat(t_data *data)
{
	long long cr;

	lock(data->table->philos[data->id].left_fork);
	ph_print("has taken a fork", data);
	lock(data->table->philos[data->id].right_fork);
	data->table->philos[data->id].last_eat = ph_updateTime(data->table) - data->table->start_milis;
	ph_print("has taken a fork", data);
	ph_print("is eating", data);
	cr = ph_updateTime(data->table);
	while (cr + data->table->tte > ph_updateTime(data->table))
		usleep(200);
	unlock(data->table->philos[data->id].left_fork);
	unlock(data->table->philos[data->id].right_fork);
	data->table->philos[data->id].eat_count++;
}

void ph_sleep(t_data *data)
{
	long cr;

	ph_print("is sleeping", data);
	cr = ph_updateTime(data->table);
	while (cr + data->table->tte > ph_updateTime(data->table))
		usleep(200);
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
