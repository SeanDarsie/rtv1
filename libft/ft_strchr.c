/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:13:12 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:34:12 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s);
	if (s)
	{
		while (i <= l)
		{
			if (s[i] == (char)c)
				return ((char*)&s[i]);
			i++;
		}
	}
	return (NULL);
}
