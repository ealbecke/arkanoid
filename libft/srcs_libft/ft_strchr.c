/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:06:04 by clegrand          #+#    #+#             */
/*   Updated: 2015/03/23 17:13:30 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s && !*s && c == 0)
		return ((char *)s);
	else if (!s || !*s)
		return (NULL);
	if (*s == (char)c)
		return ((char *)s);
	return (ft_strchr(s + 1, c));
}
