/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:10:53 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 03:36:23 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_table table;
	if (ph_check_arg(ac, av, &table))
		ph_exit();
	ph_init_table(ac, av, &table);
	ph_init_philos(&table);
	return (0);
}
