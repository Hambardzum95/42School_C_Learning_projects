/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:53:59 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:54:00 by hmkrtchy         ###   ########.fr       */
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

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*text;
	char	*st;
	int		i;

	st = 0;
	if (s && f)
	{
		if (!(text = (char *)malloc(mystrlen(s) + 1)))
			return (0);
		st = text;
		i = 0;
		while (*s != '\0')
			*text++ = f(i++, *s++);
		*text = 0;
	}
	return (st);
}
