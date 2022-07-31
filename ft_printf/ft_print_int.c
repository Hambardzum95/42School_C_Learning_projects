/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:02:22 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:02:26 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_mindigits(long n, int w2)
{
	int		l;
	int		digits;

	l = (n == 0) ? 0 : ft_intlen(n);
	digits = (n >= 0) ? l : l - 1;
	if (n < 0)
	{
		ft_putchar('-');
		ft_putzeros(w2 - digits);
		if (n != 0)
			ft_putnbr(-n);
	}
	else
	{
		ft_putzeros(w2 - digits);
		if (n == 0 && w2 < 0)
		{
			ft_putnbr(0);
			return (1);
		}
		if (n != 0)
			ft_putnbr(n);
	}
	return (ft_mindigits_senseless(n, digits, w2, l));
}

int		ft_zeropad(long n, int w1, int l)
{
	if (n == 0)
	{
		if (w1)
			ft_putzeros(w1);
		else
			ft_putnbr(0);
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putzeros(w1 - l);
		ft_putnbr(-n);
	}
	else if (n > 0)
	{
		ft_putzeros(w1 - l);
		ft_putnbr(n);
	}
	return ((w1 - l) >= 0 ? w1 : l);
}

int		ft_count_len(long n, int w2)
{
	int		l;
	int		digits;

	l = (n == 0) ? 0 : ft_intlen(n);
	digits = (n >= 0) ? l : l - 1;
	if (n == 0 && w2 < 0)
		return (1);
	if ((w2 - digits) >= 0)
		return ((n >= 0) ? w2 : w2 + 1);
	return (l);
}

int		ft_intlen(long n)
{
	int		l;

	l = (n >= 0) ? 1 : 2;
	while (n / 10)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int		ft_print_int(va_list args, t_convert *flags, bool isunsigned)
{
	long	n;
	int		w1;
	int		w2;
	int		l;

	n = va_arg(args, int);
	ft_make_unsigned(isunsigned, &n);
	l = ft_intlen(n);
	w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
	: flags->precisionbefore;
	w2 = flags->minwidth != 0 ? flags->minwidth : flags->precision;
	ft_checkalign(flags, &w1);
	if (flags->mindigits)
		return (ft_mindigits_alllogic(n, flags, w1, w2));
	else if (flags->leftalign)
		return (ft_leftalign_int(n, w1, l));
	else if (flags->zeropad)
		return (ft_zeropad(n, w1, l));
	return (ft_rightalign_int(n, w1, l));
}
