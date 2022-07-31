/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root_of_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:51:42 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:51:43 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_root_of_num(long a, int d)
{
	long	num;
	int		sign;

	sign = 1;
	if (a < 0 && (d % 2))
	{
		sign = -1;
		a *= -1;
	}
	else if (a < 0 && !(d % 2))
		return (0);
	num = 1;
	while (ft_pow(num, d) < a)
		num++;
	if (ft_pow(num, d) > a)
		return (0);
	return (num * sign);
}
