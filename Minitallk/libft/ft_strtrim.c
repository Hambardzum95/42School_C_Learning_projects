/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:56:19 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:56:22 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CHECK(x) (*x == ' ' || *x == '\t' || *x == '\n')

static int	check_end(const char *s)
{
	while (CHECK(s))
	{
		s++;
		if (*s == '\0')
			return (1);
	}
	return (0);
}

static int	trimlen(const char *s)
{
	int		i;

	while (CHECK(s))
		s++;
	i = 0;
	while (*s++ != '\0')
	{
		i++;
		if (CHECK(s) && check_end(s))
			return (i);
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*txt;
	char	*st;

	if (!s)
		return ((void*)0);
	if (!(txt = (char *)malloc(trimlen(s) + 1)))
		return (0);
	st = txt;
	while (CHECK(s))
		s++;
	while (*s != '\0')
	{
		if (check_end(s))
			break ;
		*txt++ = *s++;
	}
	*txt = 0;
	return (st);
}
