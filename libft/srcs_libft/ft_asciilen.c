/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asciilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:19:01 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/15 21:30:31 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_asciilen(const char *str)
{
	if (str && ft_isascii(*str))
		return (ft_asciilen(str + 1) + 1);
	return (0);
}
