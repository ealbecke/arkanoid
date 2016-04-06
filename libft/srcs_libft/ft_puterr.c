/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 22:22:39 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/24 23:01:15 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int					ft_puterr(const char *s1, const char *s2, const char *issu)
{
	if (s1 && s2 && issu)
		ft_dprintf(FTL_OUT_ERR, "%s: [%s] %s\n", s1, s2, issu);
	else if (s1 && issu)
		ft_dprintf(FTL_OUT_ERR, "%s: %s\n", s1, issu);
	else if (issu)
		ft_dprintf(FTL_OUT_ERR, "%s\n", issu);
	return (FTL_ERROR);
}
