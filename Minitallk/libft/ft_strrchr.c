/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:56:05 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:56:07 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = 0;
	while (*s != '\0')
		if (*s++ == (unsigned char)c)
			find = (char*)s;
	if (find)
		--find;
	if (!c)
		return ((char*)s);
	return (find);
}
