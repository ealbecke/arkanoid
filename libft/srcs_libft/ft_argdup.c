/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 19:03:19 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/19 14:27:49 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_argdup(char **arg)
{
	char				**narg;
	unsigned int		i;

	if ((narg = (char **)malloc(sizeof(char *) * (ft_arglen(arg) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_arglen(arg))
	{
		narg[i] = ft_strdup(arg[i]);
		i++;
	}
	narg[i] = NULL;
	return (narg);
}
