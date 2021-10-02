/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:31:22 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/01 21:11:29 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// char *get_line(int fd, char *buffer, int BUFFER_SIZE, char *static_buff)
// {

// }

char	*get_next_line(int fd)
{
	static char	*static_buff = NULL;
	char		*buffer;
	char		*line;
	char		*swp;
	char		*line_end;
	size_t		line_len;
	ssize_t		bytes_readed;

	line_len = 0;
	line_end = NULL;
	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!line_end)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_readed] = '\0';
		if (!bytes_readed && ft_strlen(buffer))
		{
			line = ft_strdup(buffer);
			free(static_buff);
			break;
		}
		if (!bytes_readed && !ft_strlen(buffer))
		{
			free(buffer);
			if (ft_strlen(static_buff))
			{
				line = ft_strdup(static_buff);
				free(static_buff);
				return (line);
			}
			return (NULL);
		}
		if (static_buff)
		{
			swp = buffer;
			buffer = ft_strjoin(static_buff, buffer);
			free(swp);
			free(static_buff);
		}
		line_end = ft_strchr(buffer, '\n');
		if (line_end)
		{
			line_len = line_end - buffer + 1;
			line = ft_substr(buffer, 0, line_len);
			static_buff = ft_strdup(line_end + 1);
		}
		else
			static_buff = ft_strdup(buffer);
	}
	free(buffer);
	return (line);
}
