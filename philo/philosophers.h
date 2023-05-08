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
	int eat_count;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t thread;
	struct s_data *data;
} t_philo;

typedef struct s_table
{
	char **av;
	int i;
	int ac;
	int num;
	int ttd;
	int tte;
	int tts;
	int pme;
	int is_anybody_died;
	int count_ok;
	struct timeval *tv;
	long long start_milis;
	pthread_mutex_t *forks;
	pthread_mutex_t *dmx;
	t_philo *philos;
} t_table;

typedef struct s_data
{
	int id;
	t_table *table;
} t_data;

int ph_init_philo(t_table *table);
int ph_init_philos(t_table *table);
void ph_eat(t_data *data);
void ph_think(t_data *data);
void ph_sleep(t_data *data);
long long ph_updateTime(t_table *table);
int ph_init_forks(t_table *table);
int ph_init_table(int ac, char **av, t_table *table);
int ph_check_arg(int ac, char **av, t_table *table);
int ph_check_eat_count(t_table *table, t_philo *philo);
void *ph_routine(void *arg);
void ph_exit();
void ph_print(char *str, t_data *data);
long long ph_updateTime(t_table *table);
void ph_delay(int sec, t_table *table);
void lock(pthread_mutex_t *mx);
void unlock(pthread_mutex_t *mx);
#endif
