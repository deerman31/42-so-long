/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:40:50 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 22:56:18 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	game_close(t_solong *so)
{
	mlx_destroy_window(so->mlx, so->win);
	free_map(so);
	exit(0);
	return (1);
}

static int	key_operation(int keycode, t_solong *so)
{
	if (keycode == KEY_ESC)
		game_close(so);
	move_all(so, keycode);
	return (1);
}

static void	map_put_image(t_solong *so, size_t i, size_t j)
{
	if (so->split_map[i][j] == 'P')
		mlx_put_image_to_window(so->mlx, so->win, \
		so->img_data[PLAYER].img, 64 * j, 64 * i);
	else if (so->split_map[i][j] == '1')
		mlx_put_image_to_window(so->mlx, so->win, \
		so->img_data[WALL].img, 64 * j, 64 * i);
	else if (so->split_map[i][j] == 'C')
		mlx_put_image_to_window(so->mlx, so->win, \
		so->img_data[PRINCESS].img, 64 * j, 64 * i);
	else if (so->split_map[i][j] == 'E')
		mlx_put_image_to_window(so->mlx, so->win, \
		so->img_data[CASTLE].img, 64 * j, 64 * i);
	else if (so->split_map[i][j] == '0')
		mlx_put_image_to_window(so->mlx, so->win, \
		so->img_data[ROAD].img, 64 * j, 64 * i);
}

static void	map_put(t_solong *so)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (so->split_map[i])
	{
		j = 0;
		while (so->split_map[i][j])
		{
			map_put_image(so, i, j);
			j++;
		}
		i++;
	}
}

int	play_display(t_solong *so)
{
	mlx_hook(so->win, 2, 1L << 0, key_operation, so);
	mlx_hook(so->win, 17, 1L << 0, game_close, so);
	map_put(so);
	mlx_loop(so->mlx);
	return (1);
}
