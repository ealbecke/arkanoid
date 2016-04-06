/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 10:59:37 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/18 11:27:52 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_basesize(unsigned int n, unsigned int base)
{
	if (!base)
		return (0);
	if (n >= base)
		return (ft_basesize(n / base, base) + 1);
	return (1);
}
