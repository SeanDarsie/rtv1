/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:10:49 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/14 17:01:56 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s)
	{
		while (i)
		{
			if (s[i] == c)
				return ((char*)s + i);
			i--;
		}
		if (s[i] == c)
			return ((char*)s + i);
		if (i == 0)
			return (NULL);
	}
	return (NULL);
}
