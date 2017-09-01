/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:59:51 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:12:56 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (content == '\0')
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = (void*)malloc(content_size);
		if (!lst->content)
			free(lst->content);
		else
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
	}
	lst->next = NULL;
	return (lst);
}
