/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:39:31 by parinder          #+#    #+#             */
/*   Updated: 2022/11/09 16:21:41 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printf_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_printf_putstr(char *s, int len, int *count)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		ft_printf_putchar(s[i], count);
		i++;
	}
}
