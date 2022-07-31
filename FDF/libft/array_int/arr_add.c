/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:18:52 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:18:53 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

void	arr_add(int **arr, int index, int nbr)
{
	int		*new;

	if (index <= *ARR_LEN && index >= 0)
	{
		new = (int *)malloc(sizeof(int) * (*ARR_LEN + 4));
		arr_copy(new, *arr);
		new[0]++;
		arr_set(new, index, nbr);
		while (++index <= *ARR_LEN)
			arr_set(new, index, (*arr)[index]);
		free(*arr);
		*arr = new;
	}
}
