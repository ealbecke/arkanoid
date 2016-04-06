/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:35:23 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/04 15:45:58 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strflag(const char *str, const char **sflags)
{
	unsigned int		pos;

	pos = 0;
	while (str && sflags && sflags[pos] && ft_strcmp(str, sflags[pos]))
		pos++;
	if (!sflags || !sflags[pos])
		return (0);
	return (pos);
}
