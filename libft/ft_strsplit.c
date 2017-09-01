/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:20:00 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/14 15:43:45 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	int			i;
	size_t		count;

	i = 0;
	count = 0;
	if (s && c)
	{
		while (s)
		{
			if (s[i] == '\0')
				return (count);
			if (s[i] != c)
			{
				count++;
				while (s[i + 1] != c && s[i + 1] != '\0')
					i++;
			}
			i++;
		}
	}
	return (count);
}

static size_t	ft_word_length(const char *s, char c, size_t i)
{
	size_t		len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**array;
	size_t		words;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	array = (char**)malloc(sizeof(char*) * (words + 1));
	if (!array)
		return (NULL);
	else
	{
		while (i < words)
		{
			while (s[j] == c && s[j] != '\0')
				j++;
			array[i] = ft_strsub(s, j, ft_word_length(s, c, j));
			while (s[j] != c && s[j] != '\0')
				j++;
			i++;
		}
		array[i] = NULL;
	}
	return (array);
}
