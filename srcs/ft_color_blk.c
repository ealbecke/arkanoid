/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_blk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:03 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:04 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <stdlib.h>

void				ft_blk5(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color) * 4);
	(*color)[0].red = 255;
	(*color)[0].green = 255;
	(*color)[0].blue = 255;
	(*color)[1].red = .5;
	(*color)[1].green = .5;
	(*color)[1].blue = .5;
	(*color)[2].red = 100;
	(*color)[2].green = 100;
	(*color)[2].blue = 100;
	(*color)[3].red = .5;
	(*color)[3].green = .5;
	(*color)[3].blue = .5;
}

t_coor				ft_pnt(float x, float y)
{
	t_coor				coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}
