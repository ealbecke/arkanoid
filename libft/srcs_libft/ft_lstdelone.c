/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:28:00 by clegrand          #+#    #+#             */
/*   Updated: 2014/12/29 14:13:26 by clegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ltr;

	if (!alst || !*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ltr = (*alst)->next;
	free(*alst);
	(*alst)->next = ltr;
	*alst = NULL;
}
