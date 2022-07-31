/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:52:24 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:52:25 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if ((unsigned char)c == 0)
	{
		while (s[i] != '\0')
			i++;
		return (&((char*)s)[i]);
	}
	while (s[i] != '\0')
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (&((char*)s)[i]);
		i++;
	}
	return (0);
}
