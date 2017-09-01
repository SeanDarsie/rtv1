/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:27:05 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:24:30 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;
	size_t			len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		while (s[i])
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
		if (!new)
			return (NULL);
		return (new);
	}
	return (NULL);
}
