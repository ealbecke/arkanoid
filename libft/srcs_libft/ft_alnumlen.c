/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnumlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:29:08 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/15 21:29:50 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_alnumlen(const char *str)
{
	if (str && ft_isalnum(*str))
		return (ft_alnumlen(str + 1) + 1);
	return (0);
}
