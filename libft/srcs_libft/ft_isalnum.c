/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:50:03 by clegrand          #+#    #+#             */
/*   Updated: 2014/11/07 15:06:46 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (('0' <= c && c <= '9') ||
			('A' <= c && c <= 'Z') ||
			('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
