/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:20:15 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/15 21:30:57 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_printlen(const char *str)
{
	if (str && ft_isprint(*str))
		return (ft_printlen(str + 1) + 1);
	return (0);
}
