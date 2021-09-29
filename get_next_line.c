/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:31:22 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/29 06:56:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buff = NULL;
	int			BUFFER_SIZE = 1000000;
	char		*buffer;
	char		*line;
	char		*line_end;
	size_t		line_len = 0;
	ssize_t		bytes_readed;

	line_end = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (!line_end)
	{
	bytes_readed = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_readed] = '\0';

	if (static_buff)
		buffer = ft_strjoin(static_buff, buffer);

	line_end = strchr(buffer, '\n');

	if (line_end)
	{
		line_len = line_end - buffer + 1;
		line = ft_substr(buffer, 0, line_len);
		static_buff = ft_strdup(line_end + 1);
	}
	else
	{
		static_buff = ft_strdup(buffer);
	}
	}
	free(buffer);
	return (line);
}
