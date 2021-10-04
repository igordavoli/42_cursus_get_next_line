/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:46:42 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/03 19:55:05 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		i = 5;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	fd2= open("text2.txt", O_RDONLY);
	printf("Lines to get = %d\n", i);
	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);

	while (i--)
	{
		line = get_next_line(fd);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
		line = get_next_line(fd1);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
		line = get_next_line(fd2);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
	}
	return (0);
}
