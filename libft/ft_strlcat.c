/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:56:06 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/18 02:31:27 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		final;
	size_t		fill;

	d = dst;
	s = src;
	final = size;
	while (*d && final--)
		d++;
	fill = d - dst;
	final = size - fill;
	if (final == 0)
		return (fill + ft_strlen(s));
	while (*s)
	{
		if (final != 1)
		{
			*d++ = *s;
			final--;
		}
		s++;
	}
	*d = '\0';
	return (fill + (s - src));
}
