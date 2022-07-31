/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:04:50 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:04:54 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_str_max(char *s, int w2)
{
	if (w2 < 0)
		return ((int)ft_strlen(s));
	else if (w2 <= (int)ft_strlen(s))
		return (w2);
	return ((int)ft_strlen(s));
}

int		ft_str_max(char *s, int w2)
{
	int res;
	int	len;

	res = w2;
	len = (int)ft_strlen(s);
	if (w2 < 0)
	{
		ft_putstr(s);
		return (len);
	}
	while (*s && w2-- > 0)
		ft_putchar(*s++);
	if (res <= len)
		return (res);
	return (len);
}
