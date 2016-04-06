/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 15:12:36 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/24 23:03:29 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"

int					ft_next_flag(const char *str, char **new_str, char c)
{
	int					len;

	len = ft_strclen(str, c);
	if (!(*new_str = ft_strsub(str, 0, len)))
		return (FT_ERROR);
	return (len);
}

int					ft_conv_flag(const char *src, char **dst, va_list ap,
							int *sc)
{
	int					len;
	unsigned int		ldst;
	char				*sflag;
	char				*tmp_str;

	len = ft_flag(src, &sflag, ap, sc);
	ldst = ft_strlen(*dst);
	*sc = (*sc ? *sc : (int)ft_strlen(sflag));
	tmp_str = ft_strnew(ldst + *sc);
	ft_memcpy(tmp_str, *dst, ldst);
	ft_memcpy(tmp_str + ldst, sflag, *sc);
	*sc += (int)ldst;
	free(*dst);
	*dst = (sflag ? tmp_str : NULL);
	free(sflag);
	return (len);
}
