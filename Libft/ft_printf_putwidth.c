/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putwidth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:54:40 by parinder          #+#    #+#             */
/*   Updated: 2022/11/10 16:42:36 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_frontwidth(t_format *format, int len, int *count)
{
	while (format->width > len && format->minus == 0)
	{
		if (format->zero == 1)
			ft_printf_putchar(48, count);
		else
			ft_printf_putchar(32, count);
		format->width--;
	}
}

void	ft_printf_backwidth(t_format *format, int len, int *count)
{
	while (format->width > len)
	{
		if (format->zero == 1)
			ft_printf_putchar(48, count);
		else
			ft_printf_putchar(32, count);
		format->width--;
	}
}
