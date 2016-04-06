/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:30:29 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/08 10:48:38 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *k;

	k = NULL;
	while (*s)
	{
		if (*s == (char)c)
			k = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (k);
}
