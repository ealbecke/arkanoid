/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:15:05 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/08 10:28:35 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*source;
	size_t	len;
	size_t	dst_len;

	d = dest;
	source = (char *)src;
	len = size;
	while (len-- && *d)
		d++;
	dst_len = d - dest;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(source));
	while (*source != '\0')
	{
		if (len != 1)
		{
			*d++ = *source;
			len--;
		}
		source++;
	}
	*d = '\0';
	return (dst_len + (source - src));
}
