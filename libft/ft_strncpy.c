/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:27:25 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:02:44 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
