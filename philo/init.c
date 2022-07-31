/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:27:49 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/10/10 17:46:32 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->philo_num;
	while (--i >= 0)
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (0);
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philos(t_rules *rules)
{
	int	i;

	i = rules->philo_num;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].eat_count = 0;
		rules->philo[i].lf_id = i;
		rules->philo[i].rf_id = (i + 1) % rules->philo_num;
		rules->philo[i].t_last_eat = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	init_all(t_rules *rules, char **argv)
{
	rules->philo_num = ft_atoi(argv[1]);
	rules->death_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleap_time = ft_atoi(argv[4]);
	rules->eat_amount = 0;
	rules->died = 0;
	if (rules->philo_num < 1 || rules->death_time < 0 || rules->eat_time < 0 \
			|| rules->sleap_time < 0 || rules->philo_num > 250)
		return (1);
		
	if (argv[5])
	{
		rules->eat_num = ft_atoi(argv[5]);
		if (rules->eat_num <= 0)
			return (1);
	}
	else
		rules->eat_num = -1;
	if (init_mutex(rules))
		return (2);
	init_philos(rules);
	return (0);
}
