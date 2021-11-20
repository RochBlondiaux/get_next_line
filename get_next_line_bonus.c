/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:01:07 by                   #+#    #+#             */
/*   Updated: 2021/11/16 16:55:35 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd)
{
	char	*buffer;
	int		red;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	red = read(fd, buffer, BUFFER_SIZE);
	if (red < 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[red] = '\0';
	return (buffer);
}

static char	*ft_read_next(int fd, char *last_buffer)
{
	char	*new;
	char	*dest;

	dest = ft_read(fd);
	if (!dest)
		return (NULL);
	else if (!dest[0])
	{
		free (dest);
		return (last_buffer);
	}
	else if (!last_buffer)
		return (dest);
	new = ft_strjoin(last_buffer, dest);
	free (last_buffer);
	free (dest);
	return (new);
}

static char	*ft_find_nl(char *buffer, char *line)
{
	char	*new;
	size_t	lenght;

	if (!buffer || !line)
		return (NULL);
	lenght = ft_strlen(line);
	if (lenght == ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	new = ft_substr(buffer, lenght, (ft_strlen(buffer) - lenght));
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*cache[4096];
	char		*line;
	size_t		lenght;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = 0;
	if (ft_strchr(cache[fd], '\n') == -1)
	{
		lenght = ft_strlen(cache[fd]);
		cache[fd] = ft_read_next(fd, cache[fd]);
		if (lenght == ft_strlen(cache[fd]) && cache[fd])
			line = ft_substr(cache[fd], 0, lenght);
	}
	if (!cache[fd])
		return (NULL);
	if (!line && ft_strchr(cache[fd], '\n') != -1)
		line = ft_substr(cache[fd], 0, (ft_strchr(cache[fd], '\n') + 1));
	if (line)
	{
		cache[fd] = ft_find_nl(cache[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}
