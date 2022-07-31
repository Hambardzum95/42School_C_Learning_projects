/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:29 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:30 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place_2(t_stack *a, t_stack *b)
{
	int	i;

	if (a->stack[a->place] > b_max(b))
	{
		i = find_number(b, b_max(b));
		if (i != 0)
			return (--i);
	}
	else
	{
		i = find_number(b, b_min(b));
		if (i != 0)
			return (i);
		else
			return (1);
	}
	return (0);
}

int	find_place(t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	if (b->count == 0 || a->count == 0)
		return (++i);
	while (++i < b->count - 1)
		if (a->stack[a->place] < b->stack[i])
			if (a->stack[a->place] > b->stack[i + 1])
				return (++i);
	i = 0;
	if (a->stack[a->place] > b->stack[0])
		if (a->stack[a->place] < b->stack[b->count - 1])
			return (i);
	return (find_place_2(a, b));
}
