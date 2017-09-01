/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:40:55 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 17:07:00 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(const char *src)
{
	size_t		i;
	size_t		len;
	char		*dst;

	i = 0;
	len = ft_strlen(src);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	else
	{
		while (i < ft_strlen(src))
		{
			dst[i] = src[len - 1];
			i++;
			len--;
		}
		dst[ft_strlen(src)] = '\0';
		return (dst);
	}
	return (0);
}
