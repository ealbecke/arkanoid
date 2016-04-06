/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:22 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:22 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "libft.h"
#include <stdlib.h>

static void		get_rod(t_level *tlevel, int **level, int y, int x)
{
	if (tlevel->rod_l.x == 0 && tlevel->rod_l.y == 0)
	{
		tlevel->rod_l.x = x * (100 / (float)tlevel->level_width);
		tlevel->rod_l.y = y * (100 / (float)tlevel->level_height);
	}
	tlevel->rod_r.x = (x + 1) * (100 / (float)tlevel->level_width);
	tlevel->rod_r.y = (y + 1) * (100 / (float)tlevel->level_height);
	level[y][x] = 0;
}

static void		get_ball(t_level *tlevel, int **level, int y, int x)
{
	tlevel->ball.x = x * (100 / (float)tlevel->level_width);
	tlevel->ball.x += (100 / (float)tlevel->level_width) / 2;
	tlevel->ball.y = y * (100 / (float)tlevel->level_height);
	tlevel->ball.y += (100 / (float)tlevel->level_height) / 2;
	level[y][x] = 0;
}

void			get_level_line(t_level *tlevel, int **level, char *line, int y)
{
	char		**tab;
	size_t		len;
	int			x;
	int			i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	len = ft_arglen(tab);
	tlevel->level_width = len;
	if (!(level[y] = (int *)malloc(sizeof(int) * len)))
		exit(EXIT_FAILURE);
	x = 0;
	while (x < (int)len)
	{
		level[y][x] = ft_atoi(tab[x]);
		if (level[y][x] > 0 && level[y][x] <= 4)
			tlevel->bricks++;
		if (level[y][x] == 9)
			get_rod(tlevel, level, y, x);
		if (level[y][x] == 7)
			get_ball(tlevel, level, y, x);
		x++;
	}
	ft_argdel(&tab);
}
