/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:53 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:55 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a, char *print)
{
	int		t;
	int		i;

	t = a->stack[a->count - 1];
	i = a->count;
	while (--i > 0)
		a->stack[i] = a->stack[i - 1];
	a->stack[0] = t;
	print_step(a, print);
	return (1);
}
