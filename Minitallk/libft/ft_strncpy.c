/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:59:30 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:59:32 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*st;

	st = dst;
	while (*src != '\0' && len--)
		*dst++ = *src++;
	if (*src == '\0')
		while (len--)
			*dst++ = 0;
	return (st);
}
