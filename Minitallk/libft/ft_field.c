/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:44:14 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:44:17 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_field(size_t x, size_t y, char c)
{
	char	*field;
	char	*st;
	size_t	i;

	if (!(field = (char*)malloc((x + 1) * y + 1)))
		return (0);
	st = field;
	i = 1;
	while (i <= (x + 1) * y)
	{
		if (!(i++ % (x + 1)))
			*field++ = '\n';
		else
			*field++ = c;
	}
	*field = 0;
	return (st);
}
