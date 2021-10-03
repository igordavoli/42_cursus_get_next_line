/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:46:42 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/03 15:15:02 by idavoli-         ###   ########.fr       */
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
	int		i = 5;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	printf("Lines to get = %d\n", i);
	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);

	while (i--)
	{
		line = get_next_line(fd);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
	}
	return (0);
}
