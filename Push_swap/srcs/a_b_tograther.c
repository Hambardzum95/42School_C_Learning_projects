/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_tograther.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:02 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:03 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_b_tograther_2(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	if ((b->place + a->count - a->place) > a->place)
		sum += rr(a, b);
	else if ((b->place + a->count - a->place) > (b->count - b->place))
		sum += rrr(a, b);
	else
	{
		sum += rr_rrr(a, "ra", "rra");
		sum += rr_rrr(b, "rb", "rrb");
	}
	return (sum);
}

int	a_b_together(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	if (a->place <= (a->count / 2) && b->place <= (b->count / 2))
		sum += rr(a, b);
	else if (a->place > (a->count / 2) && b->place > (b->count / 2))
		sum += rrr(a, b);
	else if (a->place <= (a->count / 2) && b->place > (b->count / 2))
	{
		if ((a->place + b->count - b->place) > b->place)
			sum += rr(a, b);
		else if ((a->place + b->count - b->place) > (a->count - a->place))
			sum += rrr(a, b);
		else
		{
			sum += rr_rrr(a, "ra", "rra");
			sum += rr_rrr(b, "rb", "rrb");
		}
	}
	else
		sum += a_b_tograther_2(a, b);
	return (sum);
}
