/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:55:41 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:55:43 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		ll;

	if (!little[0])
		return ((char*)big);
	while (*big != '\0' && len)
	{
		i = 0;
		ll = len;
		while (ll && big[i] == little[i])
		{
			ll--;
			if (little[++i] == 0)
				return ((char*)big);
		}
		len--;
		big++;
	}
	return (0);
}
