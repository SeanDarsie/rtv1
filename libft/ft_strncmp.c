/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:12:35 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:15:43 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	y;

	x = 0;
	y = 0;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			x = s1[i];
			y = s2[i];
			return (x - y);
		}
		if (!s1[i] || !s2[i])
			return (x - y);
		i++;
	}
	return (0);
}
