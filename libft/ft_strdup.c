/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:57:20 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:11:50 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*dst;

	i = 0;
	len = ft_strlen(s);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst)
	{
		while (s[i])
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
