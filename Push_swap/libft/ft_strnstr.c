/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:49:07 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/12 17:49:11 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (needle[0] == '\0')
	{
		return ((char *)dst);
	}
	j = 0;
	while (j < len && dst[j])
	{
		i = 0;
		while (j < len && needle[i] && dst[j] && needle[i] == dst[j])
		{
			++i;
			++j;
		}
		if (needle[i] == '\0')
		{
			return ((char*)&dst[j - i]);
		}
		j = j - i + 1;
	}
	return (0);
}
