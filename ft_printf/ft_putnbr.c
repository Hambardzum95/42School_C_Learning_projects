/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:04:24 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:04:27 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long nb)
{
	long a;

	a = nb;
	if (a < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a / 10)
	{
		ft_putnbr(a / 10);
	}
	ft_putchar('0' + a % 10);
}
