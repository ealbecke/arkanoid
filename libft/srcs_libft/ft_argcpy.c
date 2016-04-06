/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:04:50 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/19 15:14:45 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_argcpy(char **dst, char **src)
{
	unsigned int		i;

	i = 0;
	while (dst && src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
