/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:37:30 by parinder          #+#    #+#             */
/*   Updated: 2022/11/10 16:41:51 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printf_nbrlen(size_t n, char *base, t_format *format)
{
	int		i;
	int		tmp;
	size_t	base_len;

	i = 0;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	i++;
	if (format->type == 112)
		i += 2;
	tmp = format->precision;
	while (tmp > i)
	{
		format->width--;
		tmp--;
	}
	if (format->dot && !format->precision && !n)
		i = 0;
	return (i);
}

void	ft_printf_prefix(int negativ, t_format *format, int *count)
{
	if (negativ)
		ft_printf_putchar(45, count);
	else if (format->plus && !negativ)
		ft_printf_putchar(43, count);
	else if (format->space && !negativ)
		ft_printf_putchar(32, count);
	else if ((format->type == 112) || (format->type == 120 && format->hashtag))
		ft_printf_putstr("0x", 2, count);
	else if (format->type == 88 && format->hashtag)
		ft_printf_putstr("0X", 2, count);
}

void	ft_printf_putnbr(size_t n, char *base, size_t len, int *count)
{
	size_t	base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len && (len == 0 || len > 1))
	{
		ft_printf_putnbr(n / base_len, base, len - 1, count);
		ft_printf_putchar(base[n % base_len], count);
	}
	else
		ft_printf_putchar(base[n % base_len], count);
}
