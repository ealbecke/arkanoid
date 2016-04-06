/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:32 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:33 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		open_level(char *level)
{
	int			fd_level;

	if ((fd_level = open(level, O_RDONLY)) > 0)
		return (fd_level);
	else
	{
		ft_putendl("Error");
		exit(0);
	}
	return (0);
}

static int		count_level_line(int fd_level)
{
	char		*line;
	size_t		len;
	int			ret;

	len = 0;
	line = NULL;
	while ((ret = get_next_line(fd_level, &line)))
	{
		len++;
		if (ret < 0)
			exit(1);
		free(line);
	}
	free(line);
	return (len);
}

static void		get_level_data(t_level *tlevel, int **level, char *level_file)
{
	char		*line;
	int			fd_level;
	int			y;

	y = 0;
	line = NULL;
	fd_level = open_level(level_file);
	while (get_next_line(fd_level, &line))
	{
		get_level_line(tlevel, level, line, y);
		y++;
		free(line);
	}
	free(line);
	close(fd_level);
}

int				**get_level(t_level *tlevel, char *level_file)
{
	int			**level;
	int			fd_level;
	size_t		len;

	fd_level = open_level(level_file);
	len = count_level_line(fd_level);
	tlevel->level_height = len;
	close(fd_level);
	if (!(level = (int **)malloc(sizeof(int *) * len)))
		exit(1);
	get_level_data(tlevel, level, level_file);
	tlevel->average = 100 / (float)tlevel->bricks;
	return (level);
}
