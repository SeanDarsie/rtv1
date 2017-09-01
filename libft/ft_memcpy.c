/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:22:50 by sdarsie           #+#    #+#             */
/*   Updated: 2016/12/21 16:43:47 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*s2;

	i = 0;
	s = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (dst);
}
