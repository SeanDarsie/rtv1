/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:36:24 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/11 02:11:58 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	x;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
		if (s2[i - 1] == x)
			return ((void*)dst + i);
	}
	return (NULL);
}
