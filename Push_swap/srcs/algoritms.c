/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:38 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:39 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algoritms_1(t_stack *a, t_stack *b, t_stack *c, int *sum)
{
	b->count = 0;
	b->print = 0;
	b->stack = NULL;
	c->print = 0;
	c->stack = NULL;
	make_c(a, c, 0);
	if (sorted(a) == 1)
		return (1);
	if (a->count == 2 || a->count == 3)
		*sum = alg_3(a);
	return (0);
}

int	algoritms(t_stack *a)
{
	int		sum;
	t_stack	b;
	t_stack	c;

	sum = 0;
	if (algoritms_1(a, &b, &c, &sum) == 1)
		return (0);
	if (a->count <= 5)
	{
		sum = alg_5_1(&c, &b);
		make_c(a, &c, 0);
		if (sum < alg_5_2(&c, &b))
		{
			b.print = 1;
			sum = alg_5_1(a, &b);
		}
		else
		{
			b.print = 1;
			sum = alg_5_2(a, &b);
		}
	}
	else
		sum = alg_100(a, &b);
	return (0);
}
