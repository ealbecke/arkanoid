/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:12 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:12 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			ft_floor(t_level *level, t_coor ball, t_coor delta)
{
	if (((int)((ball.y / delta.y) * 1000) % 1000) < 250 &&
			((int)((ball.y / delta.y) * 1000) % 1000) > 0 &&
			level->direction.y >= 0)
		level->direction.y = -ABS(level->direction.y);
	else if ((((int)((ball.y / delta.y) * 1000) % 1000) > 750 &&
				(int)level->direction.y <= 0) ||
			(((int)((ball.y / delta.y) * 1000) % 1000) < 0))
		level->direction.y = ABS(level->direction.y);
	else
		level->direction.x = -level->direction.x;
}
