/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:00:12 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/29 22:00:47 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

#endif
