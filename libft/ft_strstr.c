/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:50:39 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:05:26 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j])
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
	return (NULL);
}
