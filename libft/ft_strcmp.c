/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:10:09 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:00:41 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	x;
	unsigned char	y;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			x = s1[i];
			y = s2[i];
			return (x - y);
		}
		i++;
	}
	return (0);
}
