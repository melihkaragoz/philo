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
	pthread_t thread;
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
	pthread_mutex_t *forks;
	t_philo *philos;
} t_table;

typedef struct s_data
{
	int id;
	t_table *table;
} t_data;

int ph_init_philo(t_table *table);
int	ph_init_philos(t_table *table);
int	ph_init_forks(t_table *table);
int	ph_init_table(int ac, char **av, t_table *table);
int ph_check_arg(int ac, char **av, t_table *table);
void	*ph_routine(void *arg);
void ph_exit();
#endif
