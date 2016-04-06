/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:09:02 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/08 14:19:08 by clegrand         ###   ########.fr       */
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
	stc->sc = 0;
}

void				ft_stcmainclr(t_main *stc)
{
	stc->n = 0;
	stc->tot_size = 0;
}
