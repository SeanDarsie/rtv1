/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:19:52 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:16:28 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;
	char			*x;
	char			*y;

	i = 0;
	x = (char*)s1;
	y = (char*)s2;
	while (i < n)
	{
		if (x[i] != y[i])
		{
			a = x[i];
			b = y[i];
			return (a - b);
		}
		i++;
	}
	return (0);
}
