/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funtab.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:16:04 by clegrand          #+#    #+#             */
/*   Updated: 2015/01/21 19:39:56 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNTAB_H
# define FT_FUNTAB_H

typedef char	*(*t_funtab)(t_options *, va_list);

t_funtab		g_funtab[] =
{
	ft_di_arg,
	ft_s_arg,
	ft_s_arg,
	ft_di_arg,
	ft_di_arg,
	ft_di_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_c_arg,
	ft_c_arg,
	ft_p_arg,
	ft_oux_arg,
	ft_oux_arg
};

#endif
