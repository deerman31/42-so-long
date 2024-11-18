/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 03:48:40 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 21:48:37 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	height_count(const char *map)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static int	width_check(char **strs)
{
	size_t		i;
	size_t		len;

	i = 1;
	len = ft_strlen(strs[0]);
	if (len < 3)
		return (0);
	while (strs[i] != NULL)
	{
		if (len != ft_strlen(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	wall_check(char **strs, char *map)
{
	size_t		i;
	size_t		height;
	size_t		width;

	height = height_count(map) - 1;
	i = 0;
	while (strs[0][i])
	{
		if (strs[0][i] != '1' || strs[height][i] != '1')
			return (0);
		i++;
	}
	width = ft_strlen(strs[1]) - 1;
	i = 0;
	while (i <= height)
	{
		if (strs[i][0] != '1' || strs[i][width] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	all_sign_check(char *map)
{
	size_t		i;
	size_t		p_c;
	size_t		e_c;
	size_t		c_c;

	i = 0;
	p_c = 0;
	e_c = 0;
	c_c = 0;
	while (map[i] != '\0')
	{
		if (!ft_strrchr(MAP_SIGN, map[i]))
			return (0);
		if (map[i] == 'P')
			p_c++;
		if (map[i] == 'E')
			e_c++;
		if (map[i] == 'C')
			c_c++;
		i++;
	}
	if (p_c != 1 || e_c != 1 || c_c == 0)
		return (0);
	return (1);
}

int	map_error_check(t_solong *so)
{
	if (!all_sign_check(so->map) || height_count(so->map) < 3)
		return (0);
	if (!width_check(so->split_map) || !wall_check(so->split_map, so->map))
		return (0);
	if (!playable_check(so))
		return (0);
	return (1);
}
