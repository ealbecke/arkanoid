/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:40 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:41 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

void	size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	if (width <= 500 || height <= 400)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(0);
	}
}

int		init_window(GLFWwindow **window)
{
	int	width;
	int	height;

	if (!glfwInit())
		return (-1);
	*window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	if (!*window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(*window);
	glfwSetKeyCallback(*window, key_callback);
	glfwSetWindowSizeCallback(*window, size_callback);
	glfwGetFramebufferSize(*window, &width, &height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, 100.f, 100.f, 0.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, 1);
	return (0);
}
