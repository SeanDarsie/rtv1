/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:21:29 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/27 16:39:59 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst && s)
	{
		while (i < len)
		{
			dst[i] = s[start];
			start++;
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
