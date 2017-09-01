/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:09:22 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:36:38 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_numbers(const char *s)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

char			*ft_rem_ascii(const char *s)
{
	int			i;
	int			len;
	int			j;
	char		*new;

	i = 0;
	j = 0;
	len = count_numbers(s);
	if (len == 0)
		return (0);
	else
		new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
