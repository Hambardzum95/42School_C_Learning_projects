/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:02:06 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:02:14 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_print_char(va_list args, t_convert *flags)
{
	int		w1;
	char	c;

	c = va_arg(args, int);
	w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
		: flags->precisionbefore;
	ft_checkalign(flags, &w1);
	if (flags->leftalign)
	{
		ft_putchar(c);
		ft_putspace(w1 - 1);
	}
	else
	{
		if (flags->zeropad)
			ft_putzeros(w1 - 1);
		else
			ft_putspace(w1 - 1);
		ft_putchar(c);
	}
	return ((w1 - 1) >= 0 ? w1 : 1);
}
