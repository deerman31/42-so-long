/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:03:43 by ykusano           #+#    #+#             */
/*   Updated: 2023/04/26 18:00:47 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(t_solong *so)
{
	if (so->map != NULL && so->split_map != NULL)
		free_map(so);
	ft_putendl_fd("Error", 2);
	exit(1);
}
