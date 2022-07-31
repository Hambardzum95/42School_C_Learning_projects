/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:52:49 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:52:50 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	mystrlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	char	*text;
	char	*st;

	if (!(text = (char*)malloc(mystrlen(s) * sizeof(char) + 1)))
		return (0);
	st = text;
	while (*s != '\0')
		*text++ = *s++;
	*text = 0;
	return (st);
}
