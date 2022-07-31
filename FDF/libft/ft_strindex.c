/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:33:22 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:33:22 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strindex(char *haystack, char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (needle[j] == haystack[n])
		{
			if (needle[j + 1] == '\0')
				return (i);
			n++;
			j++;
		}
		i++;
	}
	return (-1);
}
