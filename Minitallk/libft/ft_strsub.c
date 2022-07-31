/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:00:10 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:00:12 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*st_sub;

	if (!s)
		return ((void*)0);
	if (!(sub = (char *)malloc(len + 1)))
		return (0);
	st_sub = sub;
	while (len--)
		*sub++ = s[start++];
	*sub = 0;
	return (st_sub);
}
