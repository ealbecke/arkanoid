/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nummoy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 11:10:43 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/30 12:00:02 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_nummoy(int *num, unsigned int n)
{
	long long int		tot;
	unsigned int		i;

	i = 0;
	tot = 0;
	while (num && i < n)
	{
		tot += num[i];
		i++;
	}
	if (n)
		tot /= n;
	return (tot);
}
