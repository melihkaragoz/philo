/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:10:47 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 03:31:38 by mkaragoz         ###   ########.fr       */
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
