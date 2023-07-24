/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:11:57 by parinder          #+#    #+#             */
/*   Updated: 2022/10/08 15:51:37 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (i);
	while (ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (!set)
		return (i);
	while (ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set) + 1;
	str = ft_substr(s1, start, (end - start));
	if (!str)
		return (0);
	return (str);
}
