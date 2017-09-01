/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:17:33 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:34:41 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && *del)
	{
		temp = *alst;
		del(temp->content, temp->content_size);
	}
	if (alst)
	{
		free(*alst);
		*alst = NULL;
	}
}
