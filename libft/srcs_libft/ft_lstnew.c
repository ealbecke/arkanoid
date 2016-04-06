/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:26:59 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 14:45:31 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	char	*ctt;
	char	*cpy;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	ctt = (void *)content;
	new->content_size = content_size;
	cpy = (char *)malloc(sizeof(*cpy) * content_size);
	while (content_size--)
		cpy[content_size] = ctt[content_size];
	new->content = cpy;
	return (new);
}
