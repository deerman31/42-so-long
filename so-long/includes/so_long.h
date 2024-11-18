/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:03:36 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 21:26:12 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

# define MAP_SIGN "10CPE\n"
# define MAP_SIGN_DUP "10CPE"
# define X 0
# define Y 1

# define PLAYER 0
# define WALL 1
# define PRINCESS 2
# define CASTLE 3
# define ROAD 4

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define DEAD_END 0
# define PROCEED 1
# define NOT_GET_PRINCESS 2
# define NOT_KEY 3
# define GAME_CLEAR 4

/*
map			= /nで区切られているmap
split_map	= ２次元配列に格納されているmap
size		= mapの縦横　xが横　yが縦
c_n			= itemの数
p_location	= playerの位置　xが横　yが縦
e_location	= endの位置　xが横　yが縦
move_count	= playerの動いた回数
*/

typedef struct s_idata
{
	void	*img;
}				t_idata;

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	t_idata	img_data[5];
	char	*map;
	char	**split_map;
	size_t	size[2];
	size_t	p_location[2];
	size_t	e_location[2];
	size_t	c_n;
	size_t	move_count;
}				t_solong;

// error
void		error_message(t_solong *so);
int			map_error_check(t_solong *so);
int			ber_check(const char *argv);
int			playable_check(t_solong *so);

int			map_generate(t_solong *so, int fd);

void		free_map(t_solong *so);

void		map_info_set(t_solong *so);

int			play_display(t_solong *so);

void		move_all(t_solong *so, int keycode);

int			map_size_check(char *map);

#endif 
