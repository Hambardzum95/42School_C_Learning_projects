/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:09:46 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/05 18:27:47 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*c;

	len = ft_strlen(s1) + 1;
	if ((c = malloc(len)) == NULL)
	{
		return (NULL);
	}
	(void)ft_memcpy(c, s1, len);
	return (c);
	free(c);
}
