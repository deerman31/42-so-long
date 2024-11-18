/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:39:49 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 01:45:32 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	restore_map(t_solong *mlx)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (mlx->split_map[i])
	{
		j = 0;
		while (mlx->split_map[i][j])
		{
			mlx->split_map[i][j] = mlx->map[k];
			k++;
			j++;
		}
		k++;
		i++;
	}
}

static int	c_recoverable(char **map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	dfs(t_solong *so, size_t y, size_t x, int *f)
{
	if (so->split_map[y][x] == 'E')
	{
		*f = 1;
		return ;
	}
	so->split_map[y][x] = '1';
	if (so->split_map[y + 1][x] != '1')
		dfs(so, y + 1, x, f);
	if (so->split_map[y - 1][x] != '1')
		dfs(so, y - 1, x, f);
	if (so->split_map[y][x + 1] != '1')
		dfs(so, y, x + 1, f);
	if (so->split_map[y][x - 1] != '1')
		dfs(so, y, x - 1, f);
	return ;
}

int	playable_check(t_solong *so)
{
	int		f;
	size_t	x;
	size_t	y;

	f = 0;
	x = so->p_location[X];
	y = so->p_location[Y];
	dfs(so, y, x, &f);
	if (f == 0)
		return (0);
	if (!c_recoverable(so->split_map))
		return (0);
	restore_map(so);
	return (1);
}
