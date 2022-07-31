/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:44 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:45 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_c_sorted(t_stack *c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*c).count)
	{
		j = i;
		while (++j < (*c).count)
			if ((*c).stack[i] > (*c).stack[j])
				ft_swap(&((*c).stack[i]), &((*c).stack[j]));
	}
}

int	make_c(t_stack *a, t_stack *c, int sorted)
{
	int		i;

	i = -1;
	(*c).count = (*a).count;
	if ((*c).stack != NULL)
		free((*c).stack);
	(*c).stack = malloc(sizeof(int) * (*c).count);
	if (!((*c).stack))
		return (0);
	while (++i < (*a).count)
		(*c).stack[i] = (*a).stack[i];
	if (sorted == 1)
		make_c_sorted(c);
	(*c).print = 0;
	return (0);
}

t_stack	*c_stack(t_stack *a, t_stack *c)
{
	c->count = 0;
	c->print = 0;
	c->stack = malloc(sizeof(int) * (a->count));
	if (!(c->stack))
		return (0);
	return (c);
}
