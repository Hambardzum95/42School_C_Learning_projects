/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:09:03 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:09:05 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	rrr(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	while (a->count - a->place > 0 && b->count - b->place > 0)
	{
		ra(a, "");
		sum += rra(b, "rrr");
		a->place++;
		b->place++;
	}
	while (b->count - b->place > 0)
	{
		sum += rra(b, "rrb");
		b->place++;
	}
	while (a->count - b->place > 0)
	{
		sum += rra(a, "rra");
		b->place++;
	}
	return (sum);
}
