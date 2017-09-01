/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:55:03 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/11 02:15:55 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char*)b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
