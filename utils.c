/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:38 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 18:41:04 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *ph_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	printf("[OK] philo created, id : %d\n", data->id);
	int i;

	i = -1;
	while (++i < 3)
	{
		printf("[HI], i'm %d\n",data->id);
		sleep(1);
	}
	return (NULL);
}
