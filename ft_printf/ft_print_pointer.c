/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:02:57 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:03:06 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_hex_digits(size_t addr)
{
	int digits;

	digits = 0;
	while (addr != 0)
	{
		addr /= 16;
		digits++;
	}
	if (digits == 0)
		return (1);
	return (digits);
}

void	ft_print_address(size_t addr, bool isupper)
{
	ft_putstr("0x");
	ft_hex(addr, isupper);
}

int		ft_print_pointer(va_list args, t_convert *flags)
{
	int		w1;
	int		w2;
	size_t	addr;

	addr = (size_t)va_arg(args, void *);
	w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
		: flags->precisionbefore;
	w2 = flags->minwidth != 0 ? flags->minwidth : flags->precision;
	if (flags->leftalign)
	{
		ft_print_address(addr, false);
		ft_putspace(w1 - (ft_count_hex_digits(addr) + 2));
	}
	else
	{
		ft_putspace(w2 - (ft_count_hex_digits(addr) + 2));
		ft_print_address(addr, false);
	}
	return ((w1 >= (ft_count_hex_digits(addr) + 2)) ? w2
			: (ft_count_hex_digits(addr) + 2));
}
