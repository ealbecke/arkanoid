/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:25:53 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:25:54 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include "arkanoid.h"
#include <GLUT/glut.h>
#include <libft.h>

extern int			g_pause;

void				draw_score(t_level *level)
{
	(void)level;
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(95, 100 - level->score);
	glVertex2f(100, 100 - level->score);
	glVertex2f(100, 100);
	glVertex2f(95, 100);
	glEnd();
}

void				draw_pause(t_level *level)
{
	t_coor			pos_dec_l;
	t_coor			pos_dec_r;
	char			*str;
	size_t			i;

	i = -1;
	pos_dec_l.x = 10;
	pos_dec_l.y = 10;
	pos_dec_r.x = 90;
	pos_dec_r.y = 90;
	draw_square(pos_dec_l, pos_dec_r, level->color[4]);
	glColor3f(0, 0, 0);
	glRasterPos2i(35, 50);
	str = NULL;
	if (g_pause == -1)
		str = "You loose !";
	else if (g_pause == 1)
		str = "Pause !";
	else if (g_pause == 2)
		str = "You Start ! Level: ";
	while (str[++i])
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	if (g_pause == 2)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level->lvl + '0');
}
