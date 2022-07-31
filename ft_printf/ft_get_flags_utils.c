/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:00:37 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:00:48 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_to_percent(const char **format, int *printed)
{
	while (**format && **format != '%')
	{
		ft_putchar(**format);
		*printed += 1;
		(*format)++;
	}
}

void	ft_helper1_helper(va_list args, t_convert *flags, t_check *checkers)
{
	checkers->isdigitexist = checkers->first;
	flags->precisionbefore = va_arg(args, int);
}

void	ft_get_flags_helper1(va_list args, const char **format,
		t_convert *flags, t_check *checkers)
{
	while (*format && (**format == '-' || **format == '0' || **format == '.'
				|| **format == '*'))
	{
		if (**format == '-')
			flags->leftalign = true;
		else if (**format == '0')
		{
			flags->zeropad = true;
			flags->zeroforhex = true;
		}
		else if (**format == '.')
		{
			flags->mindigits = true;
			checkers->first = true;
		}
		else
		{
			checkers->preccount++;
			if (checkers->preccount == 2)
				flags->precision = va_arg(args, int);
			else
				ft_helper1_helper(args, flags, checkers);
		}
		(*format)++;
	}
}

void	ft_check_format_end(const char **format)
{
	if (**format && **(format + 1))
		(*format)++;
}

void	ft_get_flags_helper2(va_list args, const char **format,
t_convert *flags, t_check *checkers)
{
	while (*format && (**format == '-' || **format == '.' || **format == '*'))
	{
		if (**format == '.')
		{
			flags->mindigits = true;
			checkers->second = true;
		}
		if (**format == '*')
			flags->precision = va_arg(args, int);
		(*format)++;
	}
}
