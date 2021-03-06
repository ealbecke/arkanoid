/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:21:12 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/09 14:25:11 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int					ft_vprintf(const char *format, va_list ap)
{
	static int			end_n = 0;
	char				*now_str;
	t_main				count;

	ft_stcmainclr(&count);
	while (format && format[count.n])
	{
		count.sc = 0;
		count.n += ft_next_flag(format + count.n, &now_str, FT_BEG_FLAG);
		if (format[count.n] == FT_BEG_FLAG)
			count.n += ft_conv_flag(format + count.n + 1, &now_str, ap,
					&count.sc) + 1;
		if (!now_str)
			return ((end_n = FT_ERROR));
		count.tot_size += (count.sc ? count.sc : (count.sc =
				(int)ft_strlen(now_str)));
		write(FT_STD_OUT, now_str, count.sc);
		free(now_str);
	}
	return ((end_n = (end_n < 0 ? end_n : count.tot_size)));
}
