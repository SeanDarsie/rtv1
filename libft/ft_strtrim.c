/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:47:22 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:38:45 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_leading(const char *s)
{
	size_t		i;

	i = 0;
	if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		return (i);
	else
	{
		while (s[i])
		{
			i++;
			if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
				return (i);
		}
	}
	return (0);
}

static size_t	ft_count_trailing(const char *s)
{
	size_t		count;
	size_t		len;

	count = 0;
	len = (ft_strlen(s) - 1);
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
	{
		count++;
		len--;
		if (s[len] != ' ' && s[len] != '\t' && s[len] != '\n')
			return (count);
	}
	return (0);
}

char			*ft_strtrim(const char *s)
{
	char		*new;
	size_t		len;
	size_t		max;
	size_t		min;
	size_t		j;

	j = 0;
	if (!s)
		return (NULL);
	max = ft_count_trailing(s);
	min = ft_count_leading(s);
	len = ((ft_strlen(s) - max) - min);
	if ((max + min) > (ft_strlen(s)))
		len = 0;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new)
	{
		while (min < (ft_strlen(s) - max) && j <= len)
			new[j++] = s[min++];
		new[j] = '\0';
		return (new);
	}
	return (0);
}
