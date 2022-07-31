/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:44:24 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:44:25 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	**memfree(char **f, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(f[j]);
	free(f);
	return (0);
}

char		**ft_field2(size_t x, size_t y, char c)
{
	char	**f;
	size_t	i;
	size_t	ii;

	if (!(f = (char**)malloc((y + 1) * sizeof(char*))))
		return (0);
	ii = 0;
	while (ii < y)
	{
		if (!(f[ii] = (char*)malloc(x * sizeof(char) + 1)))
			return ((char**)memfree(f, ii));
		i = 0;
		while (i < x)
			f[ii][i++] = c;
		f[ii++][i] = 0;
	}
	f[ii] = 0;
	return (f);
}
