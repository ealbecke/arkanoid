/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:25:42 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:25:43 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include "arkanoid.h"

extern int			g_pause;

static void			draw_rod(t_level *level)
{
	glBegin(GL_QUADS);
	glColor3f(0, 30, 255);
	glVertex2f(level->rod_l.x, level->rod_l.y);
	glColor3f(0, 30, 255);
	glVertex2f(level->rod_r.x, level->rod_l.y);
	glColor3f(0, 0, 0);
	glVertex2f(level->rod_r.x, level->rod_r.y);
	glColor3f(0, 0, 0);
	glVertex2f(level->rod_l.x, level->rod_r.y);
	glEnd();
}

static void			draw_ball(t_level *level)
{
	t_coor		delta;

	delta.x = 100 / level->level_width;
	delta.y = 100 / level->level_height;
	glBegin(GL_QUADS);
	glColor3f(255, 0, 0);
	glVertex2f(level->ball.x - delta.x / 4, level->ball.y - delta.y / 4);
	glColor3f(255, 0, 0);
	glVertex2f(level->ball.x + delta.x / 4, level->ball.y - delta.y / 4);
	glColor3f(255, 255, 255);
	glVertex2f(level->ball.x + delta.x / 4, level->ball.y + delta.y / 4);
	glColor3f(255, 0, 255);
	glVertex2f(level->ball.x - delta.x / 4, level->ball.y + delta.y / 4);
	glEnd();
}

void				draw_square(t_coor dec_l, t_coor dec_r, t_color *color)
{
	glBegin(GL_QUADS);
	glColor3f(color[0].red, color[0].green, color[0].blue);
	glVertex2f(dec_l.x, dec_l.y);
	glColor3f(color[1].red, color[1].green, color[1].blue);
	glVertex2f(dec_r.x, dec_l.y);
	glColor3f(color[2].red, color[2].green, color[2].blue);
	glVertex2f(dec_r.x, dec_r.y);
	glColor3f(color[3].red, color[3].green, color[3].blue);
	glVertex2f(dec_l.x, dec_r.y);
	glEnd();
}

static void			draw_bricks(t_level *level)
{
	t_coor		def;
	t_coor		pos;
	t_coor		pos_dec_l;
	t_coor		pos_dec_r;

	pos.y = -1;
	def.x = 100 / (float)level->level_width;
	def.y = 100 / (float)level->level_height;
	while (++pos.y < level->level_height)
	{
		pos.x = -1;
		while (++pos.x < level->level_width)
		{
			if (level->level[(int)pos.y][(int)pos.x] != 0)
			{
				pos_dec_l = ft_pnt(pos.x * def.x, pos.y * def.y);
				pos_dec_r = ft_pnt((pos.x + 1) * def.x, (pos.y + 1) * def.y);
				if (level->level[(int)pos.y][(int)pos.x] <= 5
						&& level->level[(int)pos.y][(int)pos.x] != 7)
					draw_square(pos_dec_l, pos_dec_r,
						level->color[level->level[(int)pos.y][(int)pos.x] - 1]);
			}
		}
	}
}

void				draw(t_level *level)
{
	draw_score(level);
	draw_bricks(level);
	draw_ball(level);
	draw_rod(level);
	if (g_pause != 0)
		draw_pause(level);
}
