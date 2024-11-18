/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:34:21 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 21:50:42 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_solong *so)
{
	int		width;
	int		height;
	size_t	i;

	so->img_data[PLAYER].img = mlx_xpm_file_to_image(so->mlx, \
	"images/chara.xpm", &width, &height);
	so->img_data[WALL].img = mlx_xpm_file_to_image(so->mlx, \
	"images/wall.xpm", &width, &height);
	so->img_data[PRINCESS].img = mlx_xpm_file_to_image(so->mlx, \
	"images/item.xpm", &width, &height);
	so->img_data[CASTLE].img = mlx_xpm_file_to_image(so->mlx, \
	"images/goal.xpm", &width, &height);
	so->img_data[ROAD].img = mlx_xpm_file_to_image(so->mlx, \
	"images/road.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (so->img_data[i].img == NULL)
			error_message(so);
		i++;
	}
}

void	init_map(t_solong *so)
{
	size_t	i;

	so->mlx = NULL;
	so->win = NULL;
	so->map = NULL;
	so->split_map = NULL;
	so->size[X] = 0;
	so->size[Y] = 0;
	so->p_location[X] = 0;
	so->p_location[Y] = 0;
	so->e_location[X] = 0;
	so->e_location[Y] = 0;
	so->c_n = 0;
	so->move_count = 0;
	i = 0;
	while (i < 5)
	{
		so->img_data[i].img = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_solong	so;

	init_map(&so);
	if (argc != 2 || !ber_check(argv[1]))
		error_message(&so);
	if (!map_generate(&so, open(argv[1], O_RDONLY)))
		error_message(&so);
	if (!map_error_check(&so))
		error_message(&so);
	so.mlx = mlx_init();
	if (so.mlx == NULL)
		error_message(&so);
	set_img(&so);
	so.win = mlx_new_window(so.mlx, 64 * so.size[X], 64 * so.size[Y], "42");
	if (so.win == NULL)
		error_message(&so);
	mlx_loop_hook(so.mlx, play_display, &so);
	mlx_loop(so.mlx);
	free_map(&so);
	return (0);
}
