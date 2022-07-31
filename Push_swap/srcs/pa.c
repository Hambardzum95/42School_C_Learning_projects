/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:51 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:52 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_cut(t_stack *a)
{
	int		*tmp;
	int		i;

	tmp = a->stack;
	i = -1;
	a->stack = malloc(sizeof(int) * (a->count - 1));
	if (!(a->stack))
		return (0);
	while (++i < (a->count - 1))
		a->stack[i] = tmp[i + 1];
	if (tmp != NULL)
		free(tmp);
	a->count = a->count - 1;
	return (0);
}

int	pa(t_stack *a, t_stack *b, char *print)
{
	int		*t;
	int		i;

	t = b->stack;
	i = -1;
	b->stack = malloc(sizeof(int) * (b->count + 1));
	if (!(b->stack))
		return (0);
	b->stack[0] = a->stack[0];
	while (++i < b->count)
		b->stack[i + 1] = t[i];
	if (t != NULL)
		free(t);
	b->count += 1;
	a_cut(a);
	print_step(a, print);
	return (1);
}
