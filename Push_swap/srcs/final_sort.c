/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:08 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:09 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	final_sort(t_stack *b)
{
	int	sum;
	int	b_max1;

	sum = 0;
	b_max1 = find_number(b, b_max(b)) - 1;
	if (b_max1 <= (b->count / 2))
		while (b_max1-- > 0)
			sum += ra(b, "rb");
	else
		while ((b->count - (++b_max1)) >= 0)
			sum += rra(b, "rrb");
	return (sum);
}
