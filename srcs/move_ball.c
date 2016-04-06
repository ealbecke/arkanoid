/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:28:07 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:28:07 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include "arkanoid.h"

extern int		g_pause;

static void		change_vector(t_level *level)
{
	level->direction.x = (2.4 / (level->rod_r.x - level->rod_l.x) *
			(level->ball.x - level->rod_l.x)) - 1.2;
	level->direction.y = -1;
}

static void		vector_stop(t_level *level)
{
	level->direction.x = 0;
	level->direction.y = 0;
	g_pause = -1;
}

static void		init_var(t_level *level, t_coor *pos, t_coor *delta, t_coor *ro)
{
	level->ball.x += level->direction.x;
	level->ball.y += level->direction.y;
	delta->x = 100 / (float)level->level_width;
	delta->y = 100 / (float)level->level_height;
	pos->x = (int)(level->ball.y / delta->y);
	pos->y = (int)(level->ball.x / delta->x);
	ro->x = level->rod_l.x;
	ro->y = level->rod_l.y;
}

static void		reduce_block(t_level *level, t_coor position)
{
	if (level->ball.y > 0)
	{
		if (level->level[(int)position.x][(int)position.y] == 1)
			level->score += level->average;
		if (level->level[(int)position.x][(int)position.y] != 5)
			level->level[(int)position.x][(int)position.y]--;
	}
}

void			move_ball(t_level *level)
{
	t_coor		delta;
	t_coor		rod_l;
	int			pos;
	t_coor		position;

	init_var(level, &position, &delta, &rod_l);
	pos = level->level[(int)position.x][(int)position.y];
	if (level->ball.x > 100)
		level->direction.x = -ABS(level->direction.x);
	else if (level->ball.y >= rod_l.y &&
			rod_l.x <= level->ball.x && level->ball.x <= level->rod_r.x &&
			level->ball.y < level->rod_r.y)
		change_vector(level);
	else if (level->ball.x <= 0)
		level->direction.x = ABS(level->direction.x);
	else if (level->ball.y > level->rod_r.y || level->ball.y >= 100)
		vector_stop(level);
	else if (level->ball.y <= 0 || (level->ball.x >= 0 && level->ball.x < 100 &&
				pos > 0 && pos <= 5))
	{
		reduce_block(level, position);
		ft_floor(level, level->ball, delta);
	}
}
