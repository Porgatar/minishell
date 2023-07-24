/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_initvar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:37:04 by parinder          #+#    #+#             */
/*   Updated: 2022/11/10 16:41:38 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstinit(t_format *format)
{
	format->minus = 0;
	format->dot = 0;
	format->precision = 0;
	format->zero = 0;
	format->space = 0;
	format->plus = 0;
	format->width = 0;
	format->hashtag = 0;
	format->type = 0;
}

static int	ft_setflag(const char *arg, t_format *format)
{
	int	i;

	i = 0;
	while (arg[i] == 32 || arg[i] == 35 || arg[i] == 43 || arg[i] == 48)
	{
		if (arg[i] == 32)
			format->space = 1;
		if (arg[i] == 35)
			format->hashtag = 1;
		if (arg[i] == 43)
			format->plus = 1;
		if (arg[i] == 48)
			format->zero = 1;
		i++;
	}
	return (i);
}

static void	ft_getparam(const char *arg, t_format *format)
{
	int	i;

	i = ft_setflag(arg, format);
	while (arg[i] == 45)
	{
		format->minus = 1;
		i++;
	}
	if (ft_isdigit(arg[i]))
		format->width = ft_atoi(&arg[i]);
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i] == 46)
	{
		format->dot = 1;
		if (ft_isdigit(arg[++i]))
			format->precision = ft_atoi(&arg[i]);
	}
	while (ft_isdigit(arg[i]))
		i++;
	format->type = arg[i];
}

void	ft_printf_initvar(const char *arg, t_format *format)
{
	ft_lstinit(format);
	ft_getparam(arg, format);
	if (format->type != 99 && format->type != 115
		&& format->zero && format->dot)
		format->zero = 0;
}
