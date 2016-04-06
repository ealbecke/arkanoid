/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabusson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:26:47 by jabusson          #+#    #+#             */
/*   Updated: 2015/05/03 21:26:48 by jabusson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "libft.h"
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

t_level				*create_elem(void)
{
	t_level			*new;

	new = (t_level *)malloc(sizeof(t_level));
	new->level_width = 0;
	new->level_height = 0;
	new->rod_l.x = 0;
	new->rod_l.y = 0;
	new->rod_r.x = 0;
	new->rod_r.y = 0;
	new->ball.x = 0;
	new->ball.y = 0;
	new->direction.x = -1;
	new->direction.y = -1;
	new->level = NULL;
	new->next = NULL;
	new->bricks = 0;
	new->average = 0;
	new->score = 0;
	new->lvl = 0;
	return (new);
}

void				push_elem(t_level **head, t_level *elem)
{
	t_level			*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}

t_level				*fill_list(DIR *dirp, char *cwd)
{
	struct dirent	*entry;
	t_level			*elem;
	t_level			*head;
	char			*path;

	head = NULL;
	while ((entry = readdir(dirp)) != NULL)
	{
		if (entry->d_type == DT_REG && !ft_strncmp(entry->d_name, "level", 5))
		{
			path = ft_strjoin(cwd, entry->d_name);
			elem = create_elem();
			elem->level = get_level(elem, path);
			if (head == NULL)
				head = elem;
			else
				push_elem(&head, elem);
			free(path);
		}
	}
	return (head);
}

t_level				*list_levels(void)
{
	t_level			*list;
	char			cwd[1024];
	DIR				*dirp;

	list = NULL;
	ft_bzero(cwd, 1024);
	if (!(getcwd(cwd, sizeof(cwd))))
		ft_putendl("Fatal error");
	ft_strcat(cwd, "/levels/");
	if (!(dirp = opendir(cwd)))
	{
		ft_putendl("Exit: no levels folder");
		exit(1);
	}
	list = fill_list(dirp, cwd);
	closedir(dirp);
	return (list);
}
