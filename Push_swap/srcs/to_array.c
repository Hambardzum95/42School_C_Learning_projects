/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:09:27 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:09:32 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	to_array(t_stack *a, char **argv)
{
	int		i;
	long	tmp;

	a->stack = malloc(sizeof(int) * a->count);
	if (!a->stack)
		return (0);
	i = 0;
	while (++i <= a->count)
	{
		if (ft_strncmp(argv[i], "0", 1) != 0 && ft_atoi(argv[i]) == 0)
		{
			a->error = 1;
			return (0);
		}
		tmp = ft_atoi(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			a->error = 1;
			return (0);
		}
		a->stack[i - 1] = tmp;
	}
	return (0);
}

static int	int_count(char **argv)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ')
			count++;
		i++;
	}
	count++;
	return (count);
}

void	int_array(int argc, char **argv, t_stack *a)
{
	if (argc == 2)
	{
		a->count = int_count(argv);
		to_array(a, ft_split(argv[1], ' ') - 1);
	}
	else
	{
		a->count = argc - 1;
		to_array(a, argv);
	}
}
