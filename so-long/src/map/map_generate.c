/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:56:54 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 21:33:16 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_last_check(const char *map)
{
	size_t		len;

	len = ft_strlen(map) - 1;
	if (map[len] != '\n')
		return (0);
	return (1);
}

static int	map_split(t_solong *so)
{
	so->split_map = ft_split(so->map, '\n');
	if (so->split_map == NULL)
	{
		free(so->map);
		return (-1);
	}
	return (1);
}

static char	*ft_mapjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	return (ptr);
}

int	map_generate(t_solong *so, int fd)
{
	char	*map;

	if (fd < 0)
		return (0);
	so->map = get_next_line(fd);
	if (so->map == NULL || so->map[0] == '\n')
		return (0);
	while (map_last_check(so->map))
	{
		map = get_next_line(fd);
		if (map == NULL || map[0] == '\n')
		{
			free(so->map);
			return (0);
		}
		so->map = ft_mapjoin(so->map, map);
		if (so->map == NULL || map_size_check(so->map) == 0)
			return (0);
	}
	if (map_split(so) == -1)
		return (0);
	map_info_set(so);
	return (1);
}
