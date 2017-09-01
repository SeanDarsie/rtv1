/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:52:45 by sdarsie           #+#    #+#             */
/*   Updated: 2016/11/16 21:36:14 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_number_length(int n)
{
	int			len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		ft_write_char(int n)
{
	char		c;

	c = ('0' + (n % 10));
	return (c);
}

static char		*ft_intminmax(int n)
{
	char		*s;

	if (n == 0)
	{
		s = ft_strnew(ft_strlen("0"));
		ft_strcpy(s, "0");
	}
	else if (n > 0)
	{
		s = ft_strnew(ft_strlen("2147483647"));
		ft_strcpy(s, "2147483647");
	}
	else
	{
		s = ft_strnew(ft_strlen("-2147483648"));
		ft_strcpy(s, "-2147483648");
	}
	return (s);
}

static char		*ft_write_number(char *s, int n)
{
	int			len;
	int			i;

	i = 0;
	len = ft_count_number_length(n);
	if (n < 0)
	{
		len -= 1;
		i = 1;
		n *= -1;
	}
	else
		len--;
	while (len >= 0)
	{
		s[len] = ft_write_char(n);
		len--;
		n /= 10;
	}
	if (i == 1)
		s[0] = '-';
	return (s);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*dst;

	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (ft_intminmax(n));
	else
		len = ft_count_number_length(n);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst)
	{
		dst = ft_write_number(dst, n);
		dst[len] = '\0';
		return (dst);
	}
	return (dst);
}
