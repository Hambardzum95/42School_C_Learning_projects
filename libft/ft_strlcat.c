/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:38:55 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/29 14:51:27 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t q;

	i = 0;
	q = 0;
	while (dst[i] && i < n)
		i++;
	while (src[q] && (i + q + 1) < n)
	{
		dst[i + q] = src[q];
		q++;
	}
	if (i < n)
	{
		dst[i + q] = 0;
	}
	return (i + ft_strlen(src));
}
