/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 14:19:28 by clegrand          #+#    #+#             */
/*   Updated: 2015/02/09 14:22:58 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int					ft_dprintf(int fd, const char *format, ...)
{
	static int			end_n = 0;
	va_list				ap;
	char				*now_str;
	t_main				count;

	ft_stcmainclr(&count);
	va_start(ap, format);
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
		write(fd, now_str, count.sc);
		free(now_str);
	}
	va_end(ap);
	return ((end_n = (end_n < 0 ? end_n : count.tot_size)));
}
