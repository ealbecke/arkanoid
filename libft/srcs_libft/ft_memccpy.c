/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:08:11 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 14:54:57 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;
	unsigned int	i;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	i = 0;
	while (n-- && dst && src)
	{
		strdst[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
		{
			dst = (void *)strdst;
			return ((void *)strdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
