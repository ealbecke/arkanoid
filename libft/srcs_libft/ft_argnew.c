/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:57:24 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/20 16:38:48 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char				**ft_argnew(unsigned int n)
{
	char				**arg;
	unsigned int		i;

	if ((arg = (char **)malloc(sizeof(char *) + (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		arg[i] = NULL;
		i++;
	}
	return (arg);
}
