/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:46:47 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/12 17:46:51 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *a = (const unsigned char*)s;

	while (n > 0)
	{
		n--;
		if (*(a++) == (unsigned char)c)
		{
			return ((void*)--a);
		}
	}
	return (NULL);
}
