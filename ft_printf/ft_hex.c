/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:01:23 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:01:28 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hex(unsigned long long n, bool isupper)
{
	char	c;
	int		d;

	if (isupper)
		d = 42;
	else
		d = 10;
	if (n < 16)
	{
		c = n < 10 ? n + '0' : n - d + 'a';
		ft_putchar(c);
	}
	else
	{
		ft_hex(n / 16, isupper);
		ft_hex(n % 16, isupper);
	}
}
