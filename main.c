/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:29:22 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/29 23:38:49 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

 int	main(void)
 {
	char	*line;
	int		fd;
	int 	times = 11;

	fd = open("text.txt", O_RDONLY);

	while (times--)
	{
	line = get_next_line(fd);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
	}
	return (0);
 }
