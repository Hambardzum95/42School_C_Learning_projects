/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:01:11 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:01:16 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_initialize_forhex(va_list args, t_convert *flags, int *w1, int *w2)
{
	long	n;

	n = va_arg(args, int);
	ft_make_unsigned(true, &n);
	*w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
	: flags->precisionbefore;
	*w2 = flags->minwidth != 0 ? flags->minwidth : flags->precision;
	return (n);
}

void	ft_mindigits_hex_helper_senseless(t_hex_params *params)
{
	int		ret2;

	ret2 = params->w2 - params->ret;
	params->ret = params->w2 >= params->ret ? params->w2 : params->ret;
	ft_putspace(params->w1 - params->ret);
	ft_putzeros(ret2);
	ft_hex(params->n, params->isupper);
}

int		ft_mindigits_alllogic_hex(t_convert *flags, t_hex_params *params)
{
	if (params->n == 0 && params->w2 == 0)
	{
		ft_putspace(params->w1);
		return (params->w1);
	}
	if (flags->zeroforhex && params->w2 < 0)
	{
		ft_putzeros(params->w1 - params->ret);
		ft_hex(params->n, params->isupper);
		return ((params->w1 >= params->ret) ? params->w1 : params->ret);
	}
	if (!flags->leftalign)
		ft_mindigits_hex_helper_senseless(params);
	else
	{
		ft_putzeros(params->w2 - params->ret);
		params->ret = (params->w2 >= params->ret) ? params->w2 : params->ret;
		ft_hex(params->n, params->isupper);
		ft_putspace(params->w1 - params->ret);
	}
	return ((params->w1 >= params->ret) ? params->w1 : params->ret);
}
