/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:02:35 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/09 11:13:40 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	i = -1;
	if (!size || !(ptr = malloc(size)))
		return (NULL);
	str = ptr;
	while (++i < size)
		str[i] = 0;
	return (ptr);
}
