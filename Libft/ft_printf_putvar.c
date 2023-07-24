/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putvar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:05:08 by parinder          #+#    #+#             */
/*   Updated: 2022/11/10 16:42:23 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_char(t_format *format, char c, int *count)
{
	ft_printf_frontwidth(format, 1, count);
	ft_printf_putchar(c, count);
	ft_printf_backwidth(format, 1, count);
}

static void	ft_printf_str(t_format *format, char *str, int *count)
{
	int		strlen;

	if (str)
		strlen = ft_strlen(str);
	else
		strlen = 6;
	if (format->dot && format->precision < strlen)
		strlen = format->precision;
	ft_printf_frontwidth(format, strlen, count);
	if (str)
		ft_printf_putstr(str, strlen, count);
	if (!str && strlen > 5)
		ft_printf_putstr("(null)", 6, count);
	ft_printf_backwidth(format, strlen, count);
}

static void	ft_printf_ptr(t_format *format, size_t nbr, char *base, int *count)
{
	int		nbrlen;

	if (nbr)
		nbrlen = ft_printf_nbrlen(nbr, base, format);
	else
		nbrlen = 5;
	if (format->hashtag)
		format->width -= 2;
	ft_printf_frontwidth(format, nbrlen, count);
	if (nbr)
		ft_printf_prefix(0, format, count);
	while (format->precision-- > nbrlen)
		ft_printf_putchar(48, count);
	if (nbr || format->type == 88 || format->type == 120)
		ft_printf_putnbr(nbr, base, nbrlen, count);
	else if (!nbr && nbrlen > 4)
		ft_printf_putstr("(nil)", 5, count);
	ft_printf_backwidth(format, nbrlen, count);
}

static void	ft_printf_nbr(t_format *format, \
	long long nbr, char *base, int *count)
{
	int		nbrlen;
	int		negativ;

	negativ = 0;
	if ((format->space || format->plus) && (nbr > 0))
		nbrlen = 1;
	if (nbr < 0)
	{
		negativ = 1;
		nbr *= -1;
	}
	nbrlen = ft_printf_nbrlen(nbr, base, format) + negativ;
	if (format->zero)
		ft_printf_prefix(negativ, format, count);
	ft_printf_frontwidth(format, nbrlen, count);
	if (!format->zero)
		ft_printf_prefix(negativ, format, count);
	while (format->precision > nbrlen - negativ)
	{
		ft_printf_putchar(48, count);
		format->precision--;
	}
	if (!(format->dot && !format->precision && !nbr))
		ft_printf_putnbr(nbr, base, nbrlen, count);
	ft_printf_backwidth(format, nbrlen, count);
}

void	ft_printf_putvar(t_format *format, va_list list, int *count)
{
	if (format->type == 99)
		ft_printf_char(format, va_arg(list, int), count);
	else if (format->type == 115)
		ft_printf_str(format, va_arg(list, char *), count);
	else if (format->type == 112)
		ft_printf_ptr(format, va_arg(list, unsigned long), HEX, count);
	else if (format->type == 100 || format->type == 105)
		ft_printf_nbr(format, va_arg(list, int), DEC, count);
	else if (format->type == 117)
		ft_printf_nbr(format, va_arg(list, unsigned int), DEC, count);
	else if (format->type == 120 && format->hashtag)
		ft_printf_ptr(format, va_arg(list, unsigned int), HEX, count);
	else if (format->type == 120)
		ft_printf_nbr(format, va_arg(list, unsigned int), HEX, count);
	else if (format->type == 88 && format->hashtag)
		ft_printf_ptr(format, va_arg(list, unsigned int), U_HEX, count);
	else if (format->type == 88)
		ft_printf_nbr(format, va_arg(list, unsigned int), U_HEX, count);
}
