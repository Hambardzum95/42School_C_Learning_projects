/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:59:42 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/10/10 17:47:45 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->lf_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->rf_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, philo->id, "is eating");
	philo->t_last_eat = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	philo_sleep(rules->eat_time, rules);
	(philo->eat_count)++;
	pthread_mutex_unlock(&(rules->forks[philo->lf_id]));
	pthread_mutex_unlock(&(rules->forks[philo->rf_id]));
}

void	*thread_f(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (rules->philo_num == 1)
	{
		action_print(rules, philo->id, "has taken a fork");
		return (NULL);
	}
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->died))
	{
		philo_eats(philo);
		if (rules->eat_amount)
			break ;
		action_print(rules, philo->id, "is sleeping");
		philo_sleep(rules->sleap_time, rules);
		action_print(rules, philo->id, "is thinking");
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->philo_num)
		pthread_join(philo[i].t_id, NULL);
	i = -1;
	while (++i < rules->philo_num)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	deat_checker(t_rules *rules, t_philo *philo)
{
	int	i;

	while (!(rules->eat_amount))
	{
		i = -1;
		while (++i < rules->philo_num && !(rules->died))
		{
			pthread_mutex_lock(&(rules->meal_check));
			if (time_diff(philo[i].t_last_eat, timestamp()) > rules->death_time)
			{
				action_print(rules, i, "died");
				rules->died = 1;
			}
			pthread_mutex_unlock(&(rules->meal_check));
			usleep(100);
		}
		if (rules->died)
			break ;
		i = 0;
		while (rules->eat_num != -1 && i < rules->philo_num && \
				philo[i].eat_count >= rules->eat_num)
			i++;
		if (i == rules->philo_num)
			rules->eat_amount = 1;
	}
}

int	launch_philos(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philo;
	rules->first_timestamp = timestamp();
	while (i < rules->philo_num)
	{
		if (pthread_create(&(philo[i].t_id), NULL, thread_f, &(philo[i])))
			return (1);
		philo[i].t_last_eat = timestamp();
		i++;
	}
	deat_checker(rules, rules->philo);
	exit_launcher(rules, philo);
	return (0);
}
