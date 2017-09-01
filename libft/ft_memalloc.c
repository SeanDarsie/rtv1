/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:25:13 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/11 02:11:17 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = (void*)malloc(sizeof(void) * size);
	if (mem)
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	return (NULL);
}
