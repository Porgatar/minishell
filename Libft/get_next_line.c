/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:12:35 by parinder          #+#    #+#             */
/*   Updated: 2023/02/12 16:31:09 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1) + 1;
	s2_size = ft_strlen(s2);
	str = ft_calloc(s1_size + s2_size, sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcat(str, s1, s1_size);
	ft_strlcat(str, s2, s1_size + s2_size);
	free(s1);
	free(s2);
	return (str);
}

static size_t	ft_line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	return (i);
}

static char	*ft_read_line(int fd, char *stash)
{
	char	*buffer;
	char	*line;
	int		bytes_readed;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (stash[0])
		ft_strlcat(line, stash, BUFFER_SIZE);
	while (!ft_strchr(line, 10))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		line = ft_gnl_strjoin(line, buffer);
		if (bytes_readed < BUFFER_SIZE)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	tmp = ft_read_line(fd, stash);
	line_len = ft_line_len(tmp) + 1;
	if (line_len <= ft_strlen(tmp))
		ft_strlcpy(stash, &tmp[line_len], BUFFER_SIZE);
	else
		stash[0] = 0;
	line = ft_substr(tmp, 0, line_len);
	free(tmp);
	if (!line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}
