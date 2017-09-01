/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:50:39 by sdarsie           #+#    #+#             */
/*   Updated: 2016/12/01 16:00:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char*)big + (i - j));
		}
		if (j != 0)
			i = i - j;
		i++;
	}
	return (0);
}
