/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:42:48 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/10/10 17:42:56 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				lf_id;
	int				rf_id;
	long long		t_last_eat;
	struct s_rules	*rules;
	pthread_t		t_id;
}	t_philo;

typedef struct s_rules
{
	int					philo_num;
	int					death_time;
	int					eat_time;
	int					sleap_time;
	int					eat_amount;
	int					died;
	int					eat_num;
	long long			first_timestamp;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	pthread_mutex_t		meal_check;
	t_philo				philo[250];
}	t_rules;

int			write_error(char *str);
int			ft_atoi(const char *str);
int			init_rules(t_rules *rules, char **argv);
int			init_mutex(t_rules *rules);
int			init_philos(t_rules *rules);
int			init_all(t_rules *rules, char **argv);
int			which_error(int err);
int			launch_philos(t_rules *rules);
void		deat_checker(t_rules *rules, t_philo *philos);
long long	time_diff(long long past, long long pres);
long long	timestamp(void);
void		action_print(t_rules *rules, int id, char *str);
void		exit_launcher(t_rules *rules, t_philo *philo);
void		*thread_f(void *void_philo);
void		philo_eats(t_philo *philo);
void		philo_sleep(long long time, t_rules *rules);

#endif
