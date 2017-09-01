/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <sdarsie@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:54:18 by sdarsie           #+#    #+#             */
/*   Updated: 2016/12/02 23:15:53 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check(const char *s, int x)
{
	if (s[x] == '\t')
		return (1);
	if (s[x] == '\n')
		return (1);
	if (s[x] == '\v')
		return (1);
	if (s[x] == '\f')
		return (1);
	if (s[x] == '\r')
		return (1);
	if (s[x] == ' ')
		return (1);
	if (s[x] == '+')
		return (1);
	if (s[x] == '-')
		return (1);
	else
		return (0);
}

static int	index_modifier(const char *s)
{
	int		i;

	i = 0;
	while (ft_check(s, i) == 1 && s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && (ft_isdigit(s[i + 1]) == 0))
			return (0);
		i++;
	}
	return (i);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		n;
	int		number;

	n = 1;
	number = 0;
	i = index_modifier(s);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 1)
		{
			if (s[i - 1] == '-')
				n = -1;
			number = (number * 10) + (s[i++]) - '0';
			if (ft_isdigit(s[i]) == 0)
				return (number * n);
		}
		else
			return (0);
	}
	return (number * n);
}
