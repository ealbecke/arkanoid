/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:24:16 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/24 21:55:44 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int		i;
	int					base;
	long				tot;

	i = 0;
	base = 1;
	tot = 0;
	while (str && (*str == ' ' || (9 <= *str && *str <= 13)))
		str++;
	if (str && (*str == '-' || *str == '+'))
		i++;
	if (str && (i += ft_digitlen(str + i)) > 11)
		return (FTL_ERR);
	while (str && i-- > (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			tot -= (str[i] - '0') * base;
		else
			tot += (str[i] - '0') * base;
		base *= 10;
	}
	return ((tot < FTL_B31 && tot >= FTL_INTMIN ? (int)tot : FTL_ERR));
}
