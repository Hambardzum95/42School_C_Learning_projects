/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:02 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:03 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	print_step(t_stack *a, char *print)
{
	if (a->print == 1 && ft_strncmp(print, "", 1) != 0)
	{
		write(1, print, ft_strlen(print));
		write(1, "\n", 1);
	}
}
