/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:46:08 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:46:10 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(uintmax_t a, unsigned base)
{
	int		i;

	if (!a)
		return (1);
	i = 0;
	while (a)
	{
		a /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(uintmax_t a, unsigned base)
{
	char	*res;
	char	*symbols;
	int		i;

	symbols = "0123456789abcdef";
	if (!(res = (char*)ft_memalloc((ft_numlen(a, base) + 1) * sizeof(char))))
		return (0);
	if (!a)
		*res = '0';
	i = ft_numlen(a, base) - 1;
	while (a)
	{
		res[i--] = symbols[a % base];
		a /= base;
	}
	return (res);
}
