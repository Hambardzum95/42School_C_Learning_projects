/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:04:36 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:04:40 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checkalign(t_convert *flags, int *w1)
{
	if (*w1 < 0)
	{
		flags->leftalign = true;
		flags->zeropad = false;
		*w1 *= -1;
	}
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_putspace(int n)
{
	while (n-- > 0)
		ft_putchar(' ');
}

void	ft_putzeros(int n)
{
	while (n-- > 0)
		ft_putchar('0');
}

void	ft_make_unsigned(bool isunsigned, long *n)
{
	long	unsigned_max;

	unsigned_max = 4294967296;
	if (isunsigned && *n < 0)
		*n += unsigned_max;
}
