/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:25:32 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:27:13 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <stdlib.h>

static void			ft_blk1(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color) * 4);
	(*color)[0].red = 255;
	(*color)[0].green = 255;
	(*color)[0].blue = 255;
	(*color)[1].red = 0;
	(*color)[1].green = 255;
	(*color)[1].blue = 0;
	(*color)[2].red = 0;
	(*color)[2].green = 255;
	(*color)[2].blue = 0;
	(*color)[3].red = 0;
	(*color)[3].green = 255;
	(*color)[3].blue = 0;
}

static void			ft_blk2(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color) * 4);
	(*color)[0].red = 255;
	(*color)[0].green = 255;
	(*color)[0].blue = 255;
	(*color)[1].red = 255;
	(*color)[1].green = 255;
	(*color)[1].blue = 0;
	(*color)[2].red = 255;
	(*color)[2].green = 255;
	(*color)[2].blue = 0;
	(*color)[3].red = 255;
	(*color)[3].green = 255;
	(*color)[3].blue = 0;
}

static void			ft_blk3(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color) * 4);
	(*color)[0].red = 255;
	(*color)[0].green = 255;
	(*color)[0].blue = 255;
	(*color)[1].red = 255;
	(*color)[1].green = 0;
	(*color)[1].blue = 0;
	(*color)[2].red = 255;
	(*color)[2].green = 0;
	(*color)[2].blue = 0;
	(*color)[3].red = 255;
	(*color)[3].green = 0;
	(*color)[3].blue = 0;
}

static void			ft_blk4(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color) * 4);
	(*color)[0].red = 255;
	(*color)[0].green = 255;
	(*color)[0].blue = 255;
	(*color)[1].red = 255;
	(*color)[1].green = 0;
	(*color)[1].blue = 255;
	(*color)[2].red = 200;
	(*color)[2].green = 0;
	(*color)[2].blue = 200;
	(*color)[3].red = 255;
	(*color)[3].green = 0;
	(*color)[3].blue = 255;
}

void				fill_color(t_color ***color)
{
	*color = (t_color **)malloc(sizeof(t_color *) * 5);
	ft_blk1((*color));
	ft_blk2((*color) + 1);
	ft_blk3((*color) + 2);
	ft_blk4((*color) + 3);
	ft_blk5((*color) + 4);
}
