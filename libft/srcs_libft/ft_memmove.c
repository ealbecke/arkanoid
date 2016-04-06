/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:36:28 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/10 16:42:00 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strdst;
	char	*strsrc;

	if (!dst || !src)
		return (NULL);
	i = 0;
	strsrc = (void *)src;
	strdst = dst;
	while (n--)
	{
		if (strsrc < strdst)
			strdst[n] = strsrc[n];
		else
			strdst[i] = strsrc[i];
		i++;
	}
	dst = strdst;
	return (dst);
}
