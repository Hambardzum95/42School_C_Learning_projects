/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:01:49 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:01:53 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_rightalign_int(long n, int w1, int l)
{
	ft_putspace(w1 - l);
	ft_putnbr(n);
	return ((w1 - l) >= 0 ? w1 : l);
}

int		ft_leftalign_int(long n, int w1, int l)
{
	ft_putnbr(n);
	ft_putspace(w1 - l);
	return ((w1 - l) >= 0 ? w1 : l);
}

int		ft_mindigits_senseless(long n, int digits, int w2, int l)
{
	if ((w2 - digits) >= 0)
		return ((n >= 0) ? w2 : w2 + 1);
	return (l);
}

int		ft_mindigits_alllogic(long n, t_convert *flags, int w1, int w2)
{
	int		ret;
	int		l;

	l = ft_intlen(n);
	if (flags->zeropad)
	{
		ft_zeropad(n, w1, l);
		return ((w1 - l) >= 0 ? w1 : l);
	}
	else if (flags->leftalign)
	{
		ret = ft_mindigits(n, w2);
		ft_putspace(w1 - ret);
	}
	else
	{
		ret = ft_count_len(n, w2);
		ft_putspace(w1 - ret);
		ft_mindigits(n, w2);
	}
	return ((w1 >= ret) ? w1 : ret);
}
