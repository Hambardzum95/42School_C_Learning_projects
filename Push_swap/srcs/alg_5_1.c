/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_5_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:24 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:26 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pa_correct_2(t_stack *a, t_stack *b, int *i, int *sum)
{
	int		k;

	k = -1;
	if ((b->stack[0] > a->stack[*i - 1]) && (b->stack[0] < a->stack[*i]))
	{
		if ((*i - 1) <= (a->count / 2))
		{
			while (++k < *i)
				*sum += ra(a, "ra");
			*sum += pa(b, a, "pa");
			while (--k > -1)
				*sum += rra(a, "rra");
		}
		else
		{
			while (++k < a->count - *i)
				*sum += rra(a, "rra");
			*sum += pa(b, a, "pa");
			while (--k > -1)
				*sum += ra(a, "ra");
		}
		return (1);
	}
	return (0);
}

static int	pa_correct(t_stack *a, t_stack *b)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	if (b->stack[0] < a->stack[0])
		sum += pa(b, a, "pa");
	else if (b->stack[0] > a->stack[a->count - 1])
	{
		sum += pa(b, a, "pa");
		sum += ra(a, "ra");
	}
	else
		while (++i < a->count)
			if (pa_correct_2(a, b, &i, &sum) == 1)
				break ;
	if (b->count != 0)
		sum += pa_correct(a, b);
	return (sum);
}

int	alg_5_1(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	if (a->count == 4)
		sum += pa(a, b, "pb");
	else
	{
		sum += pa(a, b, "pb");
		if (sorted(a) == 0)
			sum += pa(a, b, "pb");
	}
	sum += alg_3(a);
	sum += pa_correct(a, b);
	return (sum);
}
