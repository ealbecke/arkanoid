/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:45:32 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/30 10:47:58 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strpath(const char *origin, char *file)
{
	char				*end_path;
	size_t				size_origin;

	size_origin = ft_strlen(origin);
	end_path = ft_strnew(size_origin + ft_strlen(file) + 1);
	ft_strcpy(end_path, origin);
	end_path[size_origin] = '/';
	ft_strcat(end_path, file);
	return (end_path);
}
