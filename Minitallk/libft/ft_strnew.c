/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:55:32 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:55:34 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	long	i;

	i = (long)size;
	if (!(str = (char*)malloc(size + 1)))
		return (0);
	while (i >= 0)
		str[i--] = 0;
	return (str);
}
