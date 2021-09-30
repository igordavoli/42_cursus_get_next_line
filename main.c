/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:01:59 by faguilar          #+#    #+#             */
/*   Updated: 2021/09/30 18:23:32 by idavoli-         ###   ########.fr       */
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
	int		i;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	i = 0;
	while (i < 11)
	{
		line = get_next_line(fd);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
		i++;
	}
	return (0);
}
