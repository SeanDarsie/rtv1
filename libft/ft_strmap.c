/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:27:20 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/11 02:28:18 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*new;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
		if (!new)
			return (NULL);
		return (new);
	}
	return (NULL);
}
