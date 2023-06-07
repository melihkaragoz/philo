/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:50:24 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/06/07 16:04:24 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define PR_RED "\x1b[41;5;197m"
# define PR_GRN "\x1b[42;5;10m"

typedef struct s_philo
{
	int				id;
	int				alive;
	long			last_eat;
	int				eat_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	emx;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_table
{
	char			**av;
	int				i;
	int				ac;
	int				num;
	int				ttd;
	int				tte;
	int				tts;
	int				pme;
	int				tec;
	int				is_anybody_died;
	struct timeval	*tv;
	long long		s_milis;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dmx;
	pthread_mutex_t	tmx;
	pthread_mutex_t	lmx;
	pthread_mutex_t	temx;
	t_philo			*philos;
}	t_table;

typedef struct s_data
{
	int		id;
	t_table	*table;
}	t_data;

int			ph_init_philo(t_table *table);
int			ph_init_philos(t_table *table);
int			ph_eat(t_data *data);
int			ph_init_forks(t_table *table);
int			ph_init_table(int ac, char **av, t_table *table);
int			ph_check_arg(int ac, char **av, t_table *table);
int			ph_check_death(t_table *table);
void		ph_eat_extended(t_data *data);
void		ph_think(t_data *data);
void		ph_sleep(t_data *data);
void		*ph_routine(void *arg);
void		ph_print(char *str, t_data *data);
void		lock(pthread_mutex_t *mx);
void		unlock(pthread_mutex_t *mx);
long long	ph_update_time(t_table *table);
long long	ph_update_time(t_table *table);
#endif
