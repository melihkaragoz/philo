/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:38 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/06/07 15:45:38 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ph_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	data->table->philos[data->id].id = data->id;
	data->table->philos[data->id].data = data;
	while (1)
	{
		lock(&data->table->dmx);
		lock(&data->table->temx);
		if (data->table->is_anybody_died || (data->table->pme > 0 \
			&& (data->table->tec >= (data->table->pme * data->table->num))))
		{
			unlock(&data->table->dmx);
			unlock(&data->table->temx);
			break ;
		}
		unlock(&data->table->dmx);
		unlock(&data->table->temx);
		if (ph_eat(data))
			break ;
		ph_sleep(data);
		ph_think(data);
	}
	return (NULL);
}

int	ph_eat(t_data *data)
{
	lock(&data->table->dmx);
	if (!data->table->is_anybody_died && (data->table->pme == -1 || \
		(data->table->pme > 0 && data->table->philos[data->id].eat_count \
			< data->table->pme)))
	{
		unlock(&data->table->dmx);
		lock(data->table->philos[data->id].left_fork);
		ph_print("has taken a fork", data);
		if (data->table->num == 1)
		{
			lock(&data->table->dmx);
			data->table->is_anybody_died = 1;
			unlock(&data->table->dmx);
			unlock(data->table->philos[data->id].left_fork);
			return (1);
		}
		ph_eat_extended(data);
		return (0);
	}
	else
	{
		unlock(&data->table->dmx);
		return (1);
	}
}

void	ph_sleep(t_data *data)
{
	long	cr;

	lock(&data->table->dmx);
	if (!data->table->is_anybody_died)
	{
		unlock(&data->table->dmx);
		ph_print("is sleeping", data);
		cr = ph_update_time(data->table);
		while (cr + data->table->tts > ph_update_time(data->table))
			usleep(200);
	}
	else
		unlock(&data->table->dmx);
}

void	ph_think(t_data *data)
{
	lock(&data->table->dmx);
	if (!data->table->is_anybody_died)
	{
		unlock(&data->table->dmx);
		ph_print("is thinking", data);
	}
	else
		unlock(&data->table->dmx);
}

void	ph_print(char *str, t_data *data)
{
	lock(&data->table->dmx);
	if (!data->table->is_anybody_died)
		printf("[%lld]\t%d %s\n", ph_update_time(data->table) \
			- data->table->s_milis, data->id, str);
	unlock(&data->table->dmx);
}
