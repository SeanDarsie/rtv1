/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:28:14 by sdarsie           #+#    #+#             */
/*   Updated: 2017/03/08 21:16:41 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*new;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (i < len)
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
