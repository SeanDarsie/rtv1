/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:53:25 by sdarsie           #+#    #+#             */
/*   Updated: 2017/03/16 20:28:06 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s)
	{
		while (i < size)
		{
			s[i] = '\0';
			i++;
		}
		s[i] = '\0';
		return (s);
	}
	return (0);
}
