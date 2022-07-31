/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:56:29 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:56:30 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	if (!little[0])
		return ((char*)big);
	while (*big != '\0')
	{
		i = 0;
		while (big[i] == little[i])
			if (little[++i] == '\0')
				return ((char*)big);
		big++;
	}
	return (0);
}
