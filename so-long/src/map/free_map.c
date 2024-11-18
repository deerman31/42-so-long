/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:41:04 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 22:41:13 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_data_free(t_solong *so)
{
	free(so->map);
	so->map = NULL;
	all_free(so->split_map);
	so->split_map = NULL;
}

void	free_map(t_solong *so)
{
	size_t		i;

	i = 0;
	while (i < 5)
	{
		if (so->img_data[i].img != NULL)
		{
			mlx_destroy_image(so->mlx, so->img_data[i].img);
			so->img_data[i].img = NULL;
		}
		i++;
	}
	if (so->mlx != NULL)
	{
		free(so->mlx);
		so->mlx = NULL;
	}
	so->win = NULL;
	if (so->map != NULL && so->split_map != NULL)
		map_data_free(so);
}
