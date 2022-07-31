/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:07:21 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:22 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number(t_stack *b, int number)
{
	int	i;

	i = -1;
	while (++i < b->count)
		if (b->stack[i] == number)
			break ;
	return (++i);
}
