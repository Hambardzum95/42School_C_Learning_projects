/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_max.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:46 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:47 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_max(t_stack *b)
{
	int	i;
	int	b_max;

	i = 0;
	b_max = b->stack[0];
	while (++i < b->count)
		if (b->stack[i] > b_max)
			b_max = b->stack[i];
	return (b_max);
}
