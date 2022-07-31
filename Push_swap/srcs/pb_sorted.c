/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:56 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:57 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_sorted(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	b->place = find_place(a, b);
	if (b->count == 0 || b->count == 1)
	{
		b->place = 0;
		sum += rr_rrr(a, "ra", "rra");
		sum += pa(a, b, "pb");
		if (b->count == 2 && b->stack[0] < b->stack[1])
		{
			if (a->count > 1 && a->stack[0] > a->stack[1])
			{
				sa(a, "");
				sum += sa(b, "ss");
			}
			else
				sum += sa(b, "sb");
		}
		return (sum);
	}
	sum += a_b_together(a, b);
	sum += pa(a, b, "pb");
	return (sum);
}
