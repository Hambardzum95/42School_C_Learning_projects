/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:51:56 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:51:57 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mystrlen(char **s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char		**ft_sortarr(char **s)
{
	int		i;
	int		len;
	char	*tmp;

	if (!s || !(*s))
		return (0);
	len = mystrlen(s);
	while (len-- - 1)
	{
		i = 0;
		while (s[i + 1])
		{
			if (ft_strcmp(s[i], s[i + 1]) > 0)
			{
				tmp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = tmp;
			}
			i++;
		}
	}
	return (s);
}
