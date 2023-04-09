/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:07:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/04/09 18:40:46 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ph_init_philo(t_table *table)
{
	printf("[PR] %d numarali philo olusturuluyor\n",table->i);
	t_data *data;

	data = malloc(sizeof(t_data));
	table->philos[table->i].id = table->i;
	table->philos[table->i].alive = 1;
	table->philos[table->i].last_eat = 0;
	data->id = table->i;
	data->table = table;
	if (pthread_create(&table->philos[table->i].thread, NULL, ph_routine, data))
		return (1);
	printf("[OK] %d numarali philo olusturuldu.\n",table->i);
	return (0);
}

int ph_init_philos(t_table *table)
{
	table->philos = malloc(table->num * sizeof(t_philo));
	table->i = -1;
	while (++(table->i) < table->num)
		if (ph_init_philo(table))
			return (1);
	table->i = -1;
	while (++(table->i) < table->num) // join yapilacak
		pthread_join(table->philos[table->i].thread, NULL);
	return (0);
}

int ph_init_table(int ac, char **av, t_table *table)
{
	table->ac = ac;
	table->av = av;
	table->num = atoi(av[1]);
	table->ttd = atoi(av[2]);
	table->tte = atoi(av[3]);
	table->tts = atoi(av[4]);
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
	while (++(table->i) < table->num && printf("mutex initialized, id: %d\n", table->i))
		if (pthread_mutex_init(&table->forks[table->i], NULL))
			return (1);
	return (0);
}

void ph_exit()
{
	printf("Error\n");
	exit(0);
}
