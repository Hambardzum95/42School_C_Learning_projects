/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:48 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:49 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	rr_rrr(t_stack *a, char *print1, char *print2)
{
	int	sum;

	sum = 0;
	if (a->place <= (a->count / 2))
		while (a->place-- > 0)
			sum += ra(a, print1);
	else
	{
		while ((a->count - a->place) > 0)
		{
			sum += rra(a, print2);
			a->place++;
		}
	}
	return (sum);
}
