/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:49:25 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/23 17:37:45 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_numlong(long long int n)
{
	if (n == -n && n != 0)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

static char	*ft_numdup(long long int n, int *pow)
{
	char	*str;

	if (n < 0)
	{
		*pow += 1;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		*pow += 1;
	}
	if (!(str = ft_strnew(*pow)))
		return (NULL);
	return (str);
}

char		*ft_litoa(long long int n)
{
	int				pow;
	char			*str;

	pow = 1;
	if ((str = ft_numlong(n)))
		return (str);
	if (!(str = ft_numdup(n, &pow)))
		return (NULL);
	if (!n)
	{
		*str = '0';
		return (str);
	}
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	while (pow-- >= 0 && n)
	{
		str[pow] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}
