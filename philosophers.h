#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	int id;
	int alive;
	long last_eat;
} t_philo;

typedef struct s_table
{
	char **av;
	int i;
	int	ac;
	int num;
	int ttd;
	int tte;
	int tts;
	int pme;
	pthread_mutex_t **forks;
} t_table;

int ph_init_philo();
int	ph_init_philos(t_table *table);
void ph_init_table(int ac, char **av, t_table *table);
int ph_check_arg(int ac, char **av, t_table *table);
void ph_exit();
#endif
