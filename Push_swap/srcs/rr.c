/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:40 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:42 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *a, t_stack *b)
{
	int	sum;

	sum = 0;
	while (b->place > 0 && a->place > 0)
	{
		ra(a, "");
		sum += ra(b, "rr");
		b->place--;
		a->place--;
	}
	while (b->place-- > 0)
		sum += ra(b, "rb");
	while (a->place-- > 0)
		sum += ra(a, "ra");
	return (sum);
}
