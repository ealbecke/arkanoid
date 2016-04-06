/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphalen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:04:58 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/15 21:29:02 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_alphalen(const char *str)
{
	if (str && ft_isalpha(*str))
		return (ft_alphalen(str + 1) + 1);
	return (0);
}
