/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:58 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:07:00 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates(t_stack *a)
{
	int		i;
	int		j;

	i = -1;
	while (++i < a->count)
	{
		j = i;
		while (++j < a->count)
		{
			if (a->stack[i] == a->stack[j])
			{
				a->error = 1;
				return (0);
			}
		}
	}
	return (0);
}
