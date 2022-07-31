/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:23 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:24 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a, char *print)
{
	int		i;
	int		tmp;

	tmp = a->stack[0];
	i = -1;
	while (++i < a->count - 1)
		a->stack[i] = a->stack[i + 1];
	a->stack[i] = tmp;
	print_step(a, print);
	return (1);
}
