/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:36:15 by idavoli-          #+#    #+#             */
/*   Updated: 2021/09/27 01:17:18 by idavoli-         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	remmsub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	remmsub = s_len - start;
	if (start <= s_len)
	{
		if (remmsub > len)
			sub = (char *)malloc(sizeof(char) * len + 1);
		else
			sub = (char *)malloc(sizeof(char) * remmsub + 1);
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		return (ft_strdup(""));
	return (sub);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		to_add;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	to_add = dstsize - dstlen - 1;
	if (dstsize - 1 == dstlen)
		return (dstlen + srclen);
	if (!dstsize || ((dstsize - 1) <= dstlen))
		return (srclen + dstsize);
	if ((dstsize - 1) > (dstlen + srclen))
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst + dstlen, src, to_add);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bstr;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	bstr = (char *)malloc(s1len + s2len + 1);
	if (!bstr)
		return (NULL);
	ft_strlcpy(bstr, s1, s1len + 1);
	ft_strlcat(bstr, s2, s1len + s2len + 1);
	return (bstr);
}
