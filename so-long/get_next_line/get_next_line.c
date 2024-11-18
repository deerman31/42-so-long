/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:05:19 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/05 15:05:21 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_create(const char *keep)
{
	char	*line;
	size_t	len;

	if (keep[0] == '\0')
		return (NULL);
	len = 0;
	if (gnl_strchr(keep, '\n'))
	{
		while (keep[len] != '\n')
			len++;
		len++;
	}
	else
		len = gnl_strlen(keep);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	gnl_strlcpy(line, keep, len + 1);
	return (line);
}

static char	*keep_create(char *keep)
{
	char	*ptr;
	char	*str;
	size_t	len;

	str = gnl_strchr(keep, '\n');
	if (str == NULL || str[1] == '\0')
	{
		free(keep);
		return (NULL);
	}
	str++;
	len = gnl_strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		free(keep);
		return (NULL);
	}
	gnl_strlcpy(ptr, str, len + 1);
	free(keep);
	return (ptr);
}

static char	*to_read(const int fd, char *keep)
{
	char		*buf;
	int			r_sign;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	r_sign = 1;
	while (!gnl_strchr(keep, '\n') && r_sign != 0)
	{
		r_sign = read(fd, buf, BUFFER_SIZE);
		if (r_sign < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[r_sign] = '\0';
		keep = gnl_strjoin(keep, buf);
		if (keep == NULL)
			break ;
	}
	free(buf);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = to_read(fd, keep);
	if (keep == NULL)
		return (NULL);
	line = line_create(keep);
	keep = keep_create(keep);
	if (line == NULL && keep != NULL)
	{
		free(keep);
		return (NULL);
	}
	return (line);
}
