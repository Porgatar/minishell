/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:17:10 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/02 13:50:34 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		slen;

	slen = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * slen);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s, slen);
	return (str);
}
