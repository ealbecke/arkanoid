/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbasesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 18:24:40 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/19 18:31:04 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_lbasesize(unsigned long long n, unsigned int base)
{
	if (!base)
		return (0);
	if (n >= base)
		return (ft_lbasesize(n / base, base) + 1);
	return (1);
}
