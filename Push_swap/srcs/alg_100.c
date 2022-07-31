/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:13 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:14 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alg_100_4(t_stack *a, t_stack *c, t_index *i)
{
	int	part;

	part = c->count / i->n;
	if (a->stack[i->j] >= c->stack[i->i * part])
	{
		if (a->stack[i->j] < c->stack[(i->i + 1) *part])
		{
			i->flag = 1;
			a->place = i->j;
		}
	}
	else if ((a->stack[a->count - i->j - 1] >= c->stack[i->i * part]))
	{
		if ((a->stack[a->count - i->j - 1] < c->stack[(i->i + 1) *part]))
		{
			i->flag = 1;
			a->place = a->count - i->j - 1;
		}
	}
}

static int	alg_100_3(t_stack *a, t_stack *b, t_stack *c, t_index *i)
{
	int	sum;

	sum = 0;
	i->j = -1;
	i->flag = 0;
	while (++(i->j) < a->count)
	{
		alg_100_4(a, c, i);
		if (i->flag == 1)
		{
			i->k = -1;
			sum += pb_sorted(a, b);
			return (sum);
		}
	}
	return (0);
}

static int	alg_100_2(t_stack *a, t_stack *b, t_stack *c, int n)
{
	int		sum;
	t_index	i;

	sum = 0;
	i.i = -1;
	i.k = -1;
	i.n = n;
	i.flag = 0;
	while (++(i.i) < i.n - 1)
	{
		while (++(i.k) < a->count)
			sum += alg_100_3(a, b, c, &i);
		i.k = -1;
	}
	return (sum);
}

static int	alg_100_1(t_stack *a, t_stack *b, int n)
{
	t_stack	c;
	int		sum;

	sum = 0;
	c.count = a->count;
	c.stack = malloc(sizeof(int) * c.count);
	if (!(c.stack))
		return (0);
	make_c(a, &c, 1);
	sum += alg_100_2(a, b, &c, n);
	while (a->count > 0)
	{
		a->place = 0;
		sum += pb_sorted(a, b);
	}
	sum += final_sort(b);
	while (b->count > 0)
		sum += pa(b, a, "pa");
	return (sum);
}

int	alg_100(t_stack *a, t_stack *b)
{
	t_stack	c;
	int		n;
	int		sum;
	int		count;
	int		n_final;

	n_final = 1;
	c.count = 0;
	c.print = 0;
	n = 0;
	sum = 500000;
	count = 0;
	c_stack(a, &c);
	while (++n < a->count && n < 81)
	{
		make_c(a, &c, 0);
		count = alg_100_1(&c, b, n);
		if (count < sum)
		{
			sum = count;
			n_final = n;
		}
	}
	b->print = 1;
	return (alg_100_1(a, b, n_final));
}
