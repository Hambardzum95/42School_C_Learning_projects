/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:53:35 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:53:36 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dstlen(const char *s, size_t size)
{
	int		i;

	i = 0;
	while (*s++ != 0 && size--)
		i++;
	return (i);
}

static int	mystrlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		ii;
	int		n;

	i = (size_t)mystrlen(dst);
	ii = (size_t)dstlen(dst, size);
	n = mystrlen(src);
	if (size < i)
		return (ii + n);
	while (i < (size - 1) && *src != '\0')
		dst[i++] = *src++;
	dst[i] = 0;
	return (ii + n);
}
