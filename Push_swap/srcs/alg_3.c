/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:19 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:20 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alg_3(t_stack *a)
{
	if (a->count == 2)
		return (sa(a, "sa"));
	if (a->stack[0] > a->stack[1] && a->stack[2] > a->stack[0])
		return (sa(a, "sa"));
	if (a->stack[2] > a->stack[1] && a->stack[0] > a->stack[2])
		return (ra(a, "ra"));
	if (a->stack[0] < a->stack[1] && a->stack[2] < a->stack[0])
		return (rra(a, "rra"));
	if (a->stack[1] > a->stack[2])
	{
		sa(a, "sa");
		if (a->stack[0] < a->stack[1])
			rra(a, "rra");
		else
			ra(a, "ra");
		return (2);
	}
	return (0);
}
