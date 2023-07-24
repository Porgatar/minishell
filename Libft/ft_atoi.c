/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:18 by parinder          #+#    #+#             */
/*   Updated: 2022/10/04 20:26:00 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			n = -1;
		i++;
	}
	while (nptr[i] && nptr[i] > 47 && nptr[i] < 58 && result < 2147483650)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (result > 2147483647 && n == 1)
		return (-1);
	if (result > 2147483648 && n == -1)
		return (0);
	return (result * n);
}
