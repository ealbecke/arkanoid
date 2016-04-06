/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:24:30 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:24:31 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# define GLFW_KEY_ESCAPE 256
# define GLFW_KEY_RIGHT 262
# define GLFW_KEY_LEFT 263
# define ABS(x) ((x) < 0 ? (x) * -1 : (x))

# include <GLFW/glfw3.h>

typedef struct		s_coor
{
	float				x;
	float				y;
}					t_coor;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_level
{
	int				bricks;
	float			average;
	float			score;
	int				level_width;
	int				level_height;
	int				**level;
	int				lvl;
	t_coor			direction;
	t_coor			rod_l;
	t_coor			rod_r;
	t_coor			ball;
	t_color			**color;
	struct s_level	*next;
}					t_level;

int					init_window(GLFWwindow **window);
void				size_callback(GLFWwindow *window, int width, int height);
void				key_callback(GLFWwindow *window, int key,
					int sca, int action, int mods);

void				fill_color(t_color ***color);
int					**get_level(t_level *tlevel, char *level_file);
t_level				*list_levels(void);

void				draw(t_level *level);
void				draw_square(t_coor d_l, t_coor d_r, t_color *color);
void				draw_pause(t_level *level);
void				draw_score(t_level *level);

void				get_level_line(t_level *tlevel, int **level, char *line,
					int y);

void				move_ball(t_level *level);
void				ft_floor(t_level *level, t_coor ball, t_coor delta);

void				ft_blk5(t_color **color);
t_coor				ft_pnt(float x, float y);

#endif
