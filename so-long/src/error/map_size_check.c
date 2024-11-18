/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:25:13 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/27 21:53:53 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_check(char *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			j += 1;
		i += 1;
		if (i - j > 880)
			return (0);
	}
	return (1);
}
