/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:04:12 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/18 20:22:17 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_digitlen(const char *str)
{
	if (str && ft_isdigit(*str))
		return (ft_digitlen(str + 1) + 1);
	return (0);
}
