/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:48:09 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 21:16:53 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (n-- && (s1[++i]))
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i -= j;
			n += j;
			j = 0;
		}
		if (!s2[j])
			return ((char *)(s1 + (i - j + 1)));
	}
	return (NULL);
}
