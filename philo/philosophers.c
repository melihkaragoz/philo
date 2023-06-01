/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:10:53 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/05/18 18:35:11 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock(pthread_mutex_t *mx)
{
	pthread_mutex_lock(mx);
}

void	unlock(pthread_mutex_t *mx)
{
	pthread_mutex_unlock(mx);
}

int main(int ac, char **av)
{
	t_table table;
	if (ph_check_arg(ac, av, &table) || ph_init_table(ac, av, &table))
		return (0);
	ph_init_philos(&table);
	printf("[END]\n");
	return (0);
}
