/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:03:23 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:03:29 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_leftalign_hex(long n, int w1, int ret, bool isupper)
{
	ft_hex(n, isupper);
	ft_putspace(w1 - ret);
	return ((w1 >= ret) ? w1 : ret);
}

int		ft_rightalign_hex(long n, int w1, int ret, bool isupper)
{
	ft_putspace(w1 - ret);
	ft_hex(n, isupper);
	return ((w1 >= ret) ? w1 : ret);
}

int		ft_zeropad_hex(long n, int w1, int ret, bool isupper)
{
	ft_putzeros(w1 - ret);
	ft_hex(n, isupper);
	return ((w1 >= ret) ? w1 : ret);
}

int		ft_print_hex(va_list args, t_convert *flags, bool isupper)
{
	long			n;
	int				w1;
	int				w2;
	int				ret;
	t_hex_params	*params;

	n = ft_initialize_forhex(args, flags, &w1, &w2);
	ret = ft_count_hex_digits(n);
	ft_checkalign(flags, &w1);
	if (!(params = (t_hex_params *)malloc(sizeof(params))))
		return (-1);
	params->n = n;
	params->w1 = w1;
	params->w2 = w2;
	params->ret = ret;
	params->isupper = isupper;
	if (flags->mindigits)
		return (ft_mindigits_alllogic_hex(flags, params));
	else if (flags->leftalign)
		return (ft_leftalign_hex(n, w1, ret, isupper));
	else if (flags->zeropad)
		return (ft_zeropad_hex(n, w1, ret, isupper));
	return (ft_rightalign_hex(n, w1, ret, isupper));
}
