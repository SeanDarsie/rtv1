/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:42:38 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 22:00:52 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_segfault(void)
{
	int		i;
	char	s[2];

	i = 1;
	while (i)
	{
		s[i] = 's';
		i++;
	}
}

static void	ft_in_rev(char *s1, char *s2, size_t len)
{
	while (len > 0)
	{
		s1[len - 1] = s2[len - 1];
		len--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (dst == (void*)0 || src == (void*)0)
		ft_segfault();
	s1 = (char*)dst;
	s2 = (char*)src;
	i = 0;
	if (dst && src)
	{
		if (s1 > s2)
			ft_in_rev(s1, s2, len);
		else
		{
			while (i < len)
			{
				s1[i] = s2[i];
				i++;
			}
		}
		return (dst);
	}
	return (0);
}
