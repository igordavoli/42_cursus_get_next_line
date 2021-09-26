/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:36:15 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/26 00:42:59 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

void	*ft_memcpy( void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst != NULL && src != NULL)
	{
		d = (unsigned char *) dst;
		s = (unsigned char *) src;
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize > srclen + 1)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str_dup = (char *)malloc(size);
	ft_strlcpy(str_dup, s1, size);
	return (str_dup);
}
