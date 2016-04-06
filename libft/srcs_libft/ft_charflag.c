/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:00:41 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/04 15:30:15 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_charflag(char c, const char *flags)
{
	unsigned int		pos;

	if (!flags || (pos = ft_strclen(flags, c)) == ft_strlen(flags))
		return (0);
	return (pos + 1);
}
