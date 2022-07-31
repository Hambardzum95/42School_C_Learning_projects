/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:53:55 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:53:56 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mystrlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*st;

	st = 0;
	if (s && f)
	{
		if (!(str = (char *)malloc(mystrlen(s) + 1)))
			return (0);
		st = str;
		while (*s != '\0')
			*str++ = f(*s++);
		*str = 0;
	}
	return (st);
}
