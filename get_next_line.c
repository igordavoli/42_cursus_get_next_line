/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:31:22 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/26 01:13:03 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		len = 50;
	char	*buffer;
	ssize_t	bytes_readed;

	buffer = (char *)malloc(len + 1);

	bytes_readed = read(fd, buffer, len);
	buffer[bytes_readed] = '\0';


	return (buffer);
}
