/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:02:46 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:02:49 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_percent(va_list args, t_convert *flags)
{
	int		w1;

	(void)args;
	w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
		: flags->precisionbefore;
	ft_checkalign(flags, &w1);
	if (flags->leftalign)
	{
		ft_putchar('%');
		ft_putspace(w1 - 1);
	}
	else if (flags->zeropad)
	{
		ft_putzeros(w1 - 1);
		ft_putchar('%');
	}
	else
	{
		ft_putspace(w1 - 1);
		ft_putchar('%');
	}
	return ((w1 - 1) >= 0 ? w1 : 1);
}
