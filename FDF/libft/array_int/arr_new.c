/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:19:16 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:19:17 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

int		*arr_new(char *arr)
{
	int		*new;
	int		len;
	char	**tmp;
	int		i;
	int		j;
	
	tmp = ft_strsplit(arr, ' ');
	len = ft_arraylen(tmp);
	new = (int *)malloc(sizeof(int) * (len + 1));
	i = 1;
	j = 0;
	new[0] = len;
	while (tmp[j])
	{
		if (check_arr_input(tmp[j]))
		{
			j++;
			new[0]--;
			continue ;
		}
		new[i++] = ft_atoi(tmp[j++]);
	}
	ft_arrayfree(tmp);
	return (new);
}
