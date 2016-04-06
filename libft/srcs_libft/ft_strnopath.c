/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnopath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:49:03 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/30 10:52:55 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnopath(char *over_path)
{
	char				*end_path;

	if ((end_path = ft_strrchr(over_path, '/')))
		return (end_path + 1);
	else
		return (over_path);
}
