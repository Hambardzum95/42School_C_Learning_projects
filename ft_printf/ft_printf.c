/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:04:03 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:04:07 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialize_lists(t_convert *flags, t_check *checkers)
{
	checkers->first = false;
	checkers->isdigitexist = false;
	checkers->second = false;
	checkers->preccount = 0;
	flags->minwidthbefore = 0;
	flags->minwidth = 0;
	flags->leftalign = false;
	flags->zeropad = false;
	flags->mindigits = false;
	flags->precisionbefore = 0;
	flags->precision = 0;
	flags->zeroforhex = false;
}

void	ft_specify_flags(t_convert *flags, t_check *checkers)
{
	if (flags->mindigits && !(flags->precision < 0))
		flags->zeropad = false;
	if (checkers->first && !checkers->second)
	{
		flags->minwidth = flags->minwidthbefore;
		flags->minwidthbefore = 0;
	}
	if (checkers->preccount == 1 && checkers->isdigitexist)
	{
		flags->precision = flags->precisionbefore;
		flags->precisionbefore = 0;
	}
}

int		ft_get_flags(va_list args, const char *format, int *printed)
{
	t_convert	*flags;
	t_check		*checkers;

	while (*format)
	{
		if (!(checkers = (t_check *)malloc(sizeof(checkers))))
			return (-1);
		if (!(flags = (t_convert *)malloc(sizeof(flags))))
			return (-1);
		ft_final_util(&format, flags, checkers, printed);
		ft_get_flags_helper1(args, &format, flags, checkers);
		while (*format && *format >= '0' && *format <= '9')
			flags->minwidthbefore = flags->minwidthbefore * 10 +
				(*format++ - '0');
		ft_get_flags_helper2(args, &format, flags, checkers);
		while (*format && *format >= '0' && *format <= '9')
			flags->minwidth = flags->minwidth * 10 + (*format++ - '0');
		ft_specify_flags(flags, checkers);
		if (!*format)
			break ;
		*printed += ft_get_specifiers(args, format, flags);
		format++;
	}
	return (*printed);
}

int		ft_get_specifiers(va_list args, const char *format, t_convert *flags)
{
	char c;

	c = *format;
	if (c == 'c')
		return (ft_print_char(args, flags));
	else if (c == 's')
		return (ft_print_str(args, flags));
	else if (c == 'p')
		return (ft_print_pointer(args, flags));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(args, flags, false));
	else if (c == 'u')
		return (ft_print_int(args, flags, true));
	else if (c == 'x')
		return (ft_print_hex(args, flags, false));
	else if (c == 'X')
		return (ft_print_hex(args, flags, true));
	else if (c == '%')
		return (ft_print_percent(args, flags));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		printed;
	va_list args;

	printed = 0;
	va_start(args, format);
	ft_get_flags(args, format, &printed);
	va_end(args);
	return (printed);
}
