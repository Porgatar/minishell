/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:40:26 by parinder          #+#    #+#             */
/*   Updated: 2022/11/10 16:41:19 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_printvar(const char *arg, va_list list, int *count)
{
	t_format	format;
	int			i;

	i = 0;
	if (arg[++i] == 37)
		ft_printf_putchar(arg[i], count);
	else
	{
		ft_printf_initvar(&arg[i], &format);
		ft_printf_putvar(&format, list, count);
	}
	while (arg[i] && arg[i] != 37
		&& ft_strchr("cspdiuxX", arg[i]) == 0)
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == 37)
			i += ft_printf_printvar(&format[i], list, &count);
		else
			ft_printf_putchar(format[i], &count);
		i++;
	}
	va_end(list);
	return (count);
}
