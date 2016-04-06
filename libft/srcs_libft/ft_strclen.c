/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 13:25:51 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/03 14:03:25 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strclen(const char *s, char c)
{
	if (!s)
		return (0);
	if (*s && *s != c)
		return (ft_strclen(s + 1, c) + 1);
	return (0);
}
