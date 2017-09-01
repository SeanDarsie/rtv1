/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:43:15 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/11 02:12:31 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char*)s;
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
