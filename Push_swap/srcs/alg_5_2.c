/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_5_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:31 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:32 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alg_5_2_2(t_stack *a, int *i, int *min_a, int *sum)
{
	while (++(*i) < a->count)
		if (a->stack[*min_a] > a->stack[*i])
			*min_a = *i;
	if (*min_a <= (a->count) / 2)
	{
		while ((*min_a)-- != 0)
		{
			*sum += ra(a, "ra");
			if (sorted(a) == 1)
				break ;
		}
	}
	else 
	{
		while ((*min_a)++ < a->count)
		{
			*sum += rra(a, "rra");
			if (sorted(a) == 1)
				break ;
		}
	}
}

int	alg_5_2(t_stack *a, t_stack *b)
{
	int	sum;
	int	i;
	int	min_a;

	min_a = 0;
	sum = 0;
	i = 0;
	while (a->count > 3)
	{
		alg_5_2_2(a, &i, &min_a, &sum);
		if (sorted(a) == 1)
			break ;
		sum += pa(a, b, "pb");
		i = 0;
		min_a = 0;
		if (sorted(a) == 1)
			break ;
	}
	sum += alg_3(a);
	while (b->count > 0)
		sum += pa(b, a, "pa");
	return (sum);
}
