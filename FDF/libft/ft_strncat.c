/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:34:40 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:34:41 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = str1;
	while (*str1 != '\0' && *str1 != '\n')
		str1++;
	i = 0;
	while (i < n && str2[i])
	{
		*str1 = str2[i];
		str1++;
		i++;
	}
	*str1 = '\0';
	return (tmp);
}
