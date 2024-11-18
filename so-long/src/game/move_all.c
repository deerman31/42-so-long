/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:00 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 22:40:10 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_message(t_solong *so, int num)
{
	if (num == DEAD_END)
		ft_putendl_fd("Players cannot move in that direction.", 1);
	else if (num == NOT_GET_PRINCESS)
		ft_putendl_fd("You didn't take all the princesses with you.", 1);
	else if (num == GAME_CLEAR)
	{
		ft_printf("Game clear!\nYou are stats %d\n", (int)so->move_count + 1);
		mlx_destroy_window(so->mlx, so->win);
		free_map(so);
		exit(0);
	}
}

static int	move_check(t_solong *so, int keycode)
{
	size_t	x;
	size_t	y;

	x = so->p_location[X];
	y = so->p_location[Y];
	if (keycode == KEY_W || keycode == KEY_UP)
		y -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		y += 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		x -= 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		x += 1;
	else
		return (NOT_KEY);
	if (so->split_map[y][x] == '1')
		return (DEAD_END);
	else if (so->split_map[y][x] == 'C')
		so->c_n -= 1;
	else if (so->split_map[y][x] == 'E' && (so->c_n != 0))
		return (NOT_GET_PRINCESS);
	else if (so->split_map[y][x] == 'E' && (so->c_n == 0))
		return (GAME_CLEAR);
	return (PROCEED);
}

static void	map_reload(t_solong *so, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		so->p_location[Y] -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		so->p_location[Y] += 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		so->p_location[X] -= 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		so->p_location[X] += 1;
}

void	move_all(t_solong *so, int keycode)
{
	const int	f = move_check(so, keycode);

	if (f == DEAD_END)
	{
		show_message(so, DEAD_END);
		return ;
	}
	else if (f == PROCEED)
	{
		so->split_map[so->p_location[Y]][so->p_location[X]] = '0';
		map_reload(so, keycode);
		so->split_map[so->p_location[Y]][so->p_location[X]] = 'P';
	}
	else if (f == NOT_GET_PRINCESS)
	{
		show_message(so, NOT_GET_PRINCESS);
		return ;
	}
	else if (f == NOT_KEY)
		return ;
	else if (f == GAME_CLEAR)
		show_message(so, GAME_CLEAR);
	so->move_count += 1;
	ft_printf("move : %d\n", (int)so->move_count);
}
