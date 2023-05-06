/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:07:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/05/06 17:12:21 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ph_init_philo(t_table *table)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	table->philos[table->i].id = table->i;
	table->philos[table->i].alive = 1;
	table->philos[table->i].last_eat = 0;
	table->philos[table->i].left_fork = &table->forks[table->i];
	if (table->i == table->num - 1)
		table->philos[table->i].right_fork = &table->forks[0];
	else
		table->philos[table->i].right_fork = &table->forks[table->i + 1];
	data->id = table->i;
	data->table = table;
	if (pthread_create(&table->philos[table->i].thread, NULL, ph_routine, data))
		return (1);
	// usleep(100);
	return (0);
}

int ph_init_philos(t_table *table)
{
	table->philos = malloc(table->num * sizeof(t_philo));
	table->i = -1;
	while (++(table->i) < table->num)
		if (ph_init_philo(table))
			return (1);
	// olum kontrolu
	table->i = -1;
	while (++(table->i) < table->num)
		pthread_join(table->philos[table->i].thread, NULL);
	return (0);
}

int ph_init_table(int ac, char **av, t_table *table)
{
	struct timeval *tv;

	tv = malloc(sizeof(struct timeval *));
	table->ac = ac;
	table->av = av;
	table->num = atoi(av[1]);
	table->ttd = atoi(av[2]);
	table->tte = atoi(av[3]);
	table->tts = atoi(av[4]);
	table->tv = tv;
	table->start_milis = ph_updateTime(table);
	table->is_anybody_died = 0;
	if (ac == 6)
		table->pme = atoi(av[5]);
	if (ph_init_forks(table))
		return (1);
	return (0);
}

int ph_init_forks(t_table *table)
{
	table->forks = malloc(table->num * sizeof(pthread_mutex_t));
	table->i = -1;
	while (++(table->i) < table->num)
		if (pthread_mutex_init(&table->forks[table->i], NULL))
			return (1);
	return (0);
}

void ph_exit()
{
	printf("Error\n");
	exit(0);
}
