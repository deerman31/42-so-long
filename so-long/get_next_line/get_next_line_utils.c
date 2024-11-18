/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:05:28 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/03 19:17:12 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t		i;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = gnl_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		d_len;
	size_t		s_len;

	d_len = 0;
	if (dst != NULL)
		d_len = gnl_strlen(dst);
	s_len = gnl_strlen(src);
	i = 0;
	j = d_len;
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (j + 1 < dstsize && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (d_len + s_len);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = gnl_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		ptr = malloc(sizeof(char) * (gnl_strlen(s2) + 1));
		if (ptr == NULL)
			return (NULL);
		gnl_strlcpy(ptr, s2, gnl_strlen(s2) + 1);
		return (ptr);
	}
	ptr = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (ptr == NULL)
	{
		free(s1);
		return (NULL);
	}
	gnl_strlcpy(ptr, s1, gnl_strlen(s1) + 1);
	gnl_strlcat(ptr, s2, gnl_strlen(s1) + gnl_strlen(s2) + 1);
	free(s1);
	return (ptr);
}
