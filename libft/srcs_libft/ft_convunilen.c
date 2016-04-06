/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convunilen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 12:03:53 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/20 20:08:36 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

unsigned int		ft_convunilen(wchar_t wcc)
{
	if (wcc < FTL_B7 && wcc >= 0)
		return (1);
	else if (wcc < FTL_B11 && wcc >= 0)
		return (2);
	else if (wcc < FTL_B16 && wcc >= 0)
		return (3);
	else if (wcc <= (FTL_B16 - 1) + FTL_B20 && wcc >= 0)
		return (4);
	return (0);
}
