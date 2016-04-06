/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:24:22 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 14:41:58 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tnew;
	t_list	*tlst;

	if (!lst || !f || !*f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	tnew = new;
	tlst = lst->next;
	while (tlst)
	{
		if (!(tnew->next = f(tlst)))
			return (NULL);
		tnew = tnew->next;
		tlst = tlst->next;
	}
	return (new);
}
