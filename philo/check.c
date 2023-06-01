/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:10:47 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/05/18 18:29:17 by mkaragoz         ###   ########.fr       */
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

long long 	ph_updateTime(t_table *table)
{
	lock(&table->tmx);
	gettimeofday(table->tv, NULL);
	unlock(&table->tmx);
	return ((table->tv->tv_sec * 1000) + (table->tv->tv_usec / 1000));
}
