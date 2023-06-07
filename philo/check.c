/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:10:47 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/06/07 15:45:10 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_check_arg(int ac, char **av, t_table *table)
{
	if (ac != 5 && ac != 6)
		return (1);
	table->i = 1;
	while (av[table->i] && atoi(av[table->i]) > 0)
		table->i++;
	if (table->i != ac)
		return (1);
	return (0);
}

long long	ph_update_time(t_table *table)
{
	lock(&table->tmx);
	gettimeofday(table->tv, NULL);
	unlock(&table->tmx);
	return ((table->tv->tv_sec * 1000) + (table->tv->tv_usec / 1000));
}

void	ph_eat_extended(t_data *data)
{
	long long	cr;

	lock(data->table->philos[data->id].right_fork);
	lock(&data->table->lmx);
	data->table->philos[data->id].last_eat = ph_update_time(data->table) \
		- data->table->s_milis;
	unlock(&data->table->lmx);
	ph_print("has taken a fork", data);
	ph_print("is eating", data);
	lock(&data->table->philos[data->id].emx);
	data->table->philos[data->id].eat_count++;
	unlock(&data->table->philos[data->id].emx);
	lock(&data->table->temx);
	data->table->tec++;
	unlock(&data->table->temx);
	cr = ph_update_time(data->table);
	while (cr + data->table->tte > ph_update_time(data->table))
		usleep(200);
	unlock(data->table->philos[data->id].left_fork);
	unlock(data->table->philos[data->id].right_fork);
}
