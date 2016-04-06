/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:38:56 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/10 11:43:08 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*strdst;
	char	*strsrc;

	if (!src || !dst)
		return (NULL);
	i = 0;
	strsrc = (void *)src;
	strdst = dst;
	while (n--)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	dst = strdst;
	return (dst);
}
