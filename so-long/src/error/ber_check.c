/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:08:47 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 22:34:43 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(const char *argv)
{
	size_t		i;
	char		*dot;
	const char	ber[4] = ".ber";

	dot = ft_strrchr(argv, '.');
	if (dot == NULL)
		return (0);
	i = 0;
	while (dot[i])
	{
		if (dot[i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}
