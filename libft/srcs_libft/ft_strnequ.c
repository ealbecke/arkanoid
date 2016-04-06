/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:04:59 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 21:05:57 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (*s1 && *s2 && *s1 != *s2)
		return (0);
	while (n-- && *s1 && *s2)
	{
		s1++;
		s2++;
		if (*s1 != *s2 && n)
			return (0);
	}
	return (1);
}
