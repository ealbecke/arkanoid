/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:01:59 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/08 14:19:01 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_stcoptclr(t_options *stc)
{
	stc->ck = 0;
	stc->fl = 0;
	stc->area = 0;
	stc->accu = 0;
	stc->cast = 0;
	stc->type = 0;
}
