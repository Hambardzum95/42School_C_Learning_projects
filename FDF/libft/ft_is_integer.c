/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:21:49 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:21:52 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int		ft_isinteger(char *nbr)
{
	long num;

	if (!nbr || ft_strlen(nbr) > 11)
		return (0);
	num = ft_atoi_long(nbr);
	return (num <= (long)INT_MAX && num >= (long)INT_MIN);
}
