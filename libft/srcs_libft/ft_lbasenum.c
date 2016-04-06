/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbasenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 18:30:11 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/19 18:36:52 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_lbasenum(unsigned long long n, const char *base)
{
	char				*str;
	unsigned int		b;
	unsigned int		i;

	if (!base || !(b = ft_strlen(base)))
		return (NULL);
	if (b == 1)
		return (ft_strdup(base));
	i = ft_lbasesize(n, b);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (n >= b)
	{
		str[--i] = base[n % b];
		n /= b;
	}
	*str = base[n % b];
	return (str);
}
