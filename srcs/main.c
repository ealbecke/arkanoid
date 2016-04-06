/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:54 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:27:02 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include "arkanoid.h"
#include "libft.h"
#include <stdlib.h>

int				g_pause = 2;

void			key_callback(GLFWwindow *win, int key, int sca, int act, int m)
{
	(void)sca;
	(void)m;
	if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
	{
		glfwDestroyWindow(win);
		glfwTerminate();
		exit(0);
	}
	if (key == GLFW_KEY_SPACE && act == GLFW_PRESS)
	{
		if (g_pause == 0)
			g_pause = 1;
		else if (g_pause == -1)
		{
			glfwDestroyWindow(win);
			glfwTerminate();
			exit(0);
		}
		else
			g_pause = 0;
	}
}

void			catch_move(GLFWwindow *window, t_level *level)
{
	int			move_left;
	int			move_right;

	move_left = glfwGetKey(window, GLFW_KEY_LEFT);
	move_right = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (move_left == GLFW_PRESS && level->rod_l.x >= 0)
	{
		level->rod_l.x -= 3;
		level->rod_r.x -= 3;
	}
	if (move_right == GLFW_PRESS && level->rod_r.x <= 100)
	{
		level->rod_l.x += 3;
		level->rod_r.x += 3;
	}
}

static void		pause_zero(t_level *level, GLFWwindow *window)
{
	if (g_pause == 0)
	{
		catch_move(window, level);
		move_ball(level);
	}
}

static void		error_message(void)
{
	ft_putstr("Nothing turned in folder levels/\n");
	exit (1);
}

int				main(void)
{
	GLFWwindow	*window;
	t_level		*level;

	if (!(level = list_levels()))
		error_message();
	level->lvl = 1;
	fill_color(&level->color);
	init_window(&window);
	while (!glfwWindowShouldClose(window))
	{
		if (level->score > 99.9 && level->next)
		{
			level->next->lvl = level->lvl + 1;
			level = level->next;
			g_pause = 2;
			fill_color(&level->color);
		}
		glClear(GL_COLOR_BUFFER_BIT);
		draw(level);
		pause_zero(level, window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}
