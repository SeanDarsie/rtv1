/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <sdarsie@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:56:32 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:14:11 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				index;
	unsigned int	i;

	index = 0;
	i = 0;
	if (s && f)
	{
		while (s[index])
		{
			f(i, &s[i]);
			i++;
			index++;
		}
	}
}
