/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:45:31 by clegrand          #+#    #+#             */
/*   Updated: 2015/03/04 14:54:32 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_cntwrd(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str && *str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str)
			i++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
	}
	return (i);
}
