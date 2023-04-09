/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:07:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 03:37:41 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ph_init_philo()
{
	return (0);
}

int	ph_init_philos(t_table *table)
{
	return (0);
}

void ph_init_table(int ac, char **av, t_table *table)
{
	table->ac = ac;
	table->av = av;
	table->num = atoi(av[1]);
	table->ttd = atoi(av[2]);
	table->tte = atoi(av[3]);
	table->tts = atoi(av[4]);
	table->pme = atoi(av[5]);
	return (1);
}

void ph_exit()
{
	printf("Error\n");
	exit(0);
}
