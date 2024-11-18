/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 04:07:39 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 16:55:52 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pe_location_set(t_solong *so)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (so->split_map[y] != NULL)
	{
		x = 0;
		while (so->split_map[y][x])
		{
			if (so->split_map[y][x] == 'P')
			{
				so->p_location[X] = x;
				so->p_location[Y] = y;
			}
			if (so->split_map[y][x] == 'E')
			{
				so->e_location[X] = x;
				so->e_location[Y] = y;
			}
			x++;
		}
		y++;
	}
}

static void	c_info_set(t_solong *so)
{
	size_t		i;

	i = 0;
	so->c_n = 0;
	while (so->map[i])
	{
		if (so->map[i] == 'C')
			so->c_n++;
		i++;
	}
}

void	map_info_set(t_solong *so)
{
	size_t		count;

	count = 0;
	while (so->split_map[count])
		count++;
	so->size[X] = ft_strlen(so->split_map[0]);
	so->size[Y] = count;
	pe_location_set(so);
	c_info_set(so);
}
