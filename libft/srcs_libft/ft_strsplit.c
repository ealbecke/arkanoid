/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:11:39 by clegrand          #+#    #+#             */
/*   Updated: 2015/03/24 12:34:14 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_splitmtx(char const *s, char c, int *j)
{
	int		i;
	char	**sstr;

	i = -1;
	*j = 1;
	while (s && (s[++i - 1] || i - 1 == -1))
	{
		if (!s[i] || (s[i] == c && i - 1 != -1 && s[i - 1] != c))
		{
			*j += 1;
		}
	}
	if (!(sstr = (char **)malloc(sizeof(char *) * (*j))))
		return (NULL);
	sstr[*j - 1] = NULL;
	return (sstr);
}

static char	*ft_splitstr(char const *s, char c)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!*s || !(str = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	j = -1;
	while (++j < i - 1)
		str[j] = s[j];
	str[j] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int				x;
	int				y;
	int				j;
	unsigned int	n;
	char			**sstr;

	while (s && *s == c)
		s++;
	if (!(sstr = ft_splitmtx(s, c, &j)))
		return (NULL);
	y = -1;
	n = 0;
	while (--j)
	{
		if (!(sstr[++y] = ft_splitstr(s + n, c)))
			return (sstr);
		x = -1;
		while (sstr[y][++x])
			n++;
		while (s[n] == c)
			s++;
	}
	return (sstr);
}
