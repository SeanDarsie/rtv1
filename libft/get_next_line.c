/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:15:43 by sdarsie           #+#    #+#             */
/*   Updated: 2017/03/23 18:07:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_buf(char **line, char **save)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!ft_strchr(*save, '\n'))
		return (0);
	while (save[0][i])
	{
		if (save[0][i] == '\n')
		{
			tmp = *save;
			*line = ft_strsub(*save, 0, i);
			*save = ft_strsub(*save, i + 1, ft_strlen(*save) - i);
			free(tmp);
			return (1);
		}
		++i;
	}
	return (0);
}

static int	checker(const int fd, char **save, char **line)
{
	char	buf[BUFF_SIZE + 1];

	if (!line || read(fd, buf, 0) < 0 || fd < 0 || fd > 1024)
		return (-1);
	if (*save == NULL)
		*save = ft_strnew(BUFF_SIZE + 1);
	return (0);
}

static int	final_line(char **save, char **line)
{
	*line = ft_strdup(*save);
	ft_strclr(*save);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	int			red;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (checker(fd, &save, line) == -1)
		return (-1);
	if (parse_buf(line, &save))
		return (1);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = '\0';
		tmp = save;
		save = ft_strjoin(save, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE);
		if (parse_buf(line, &save))
			return (1);
	}
	if (save[0] != '\0')
		return (final_line(&save, line));
	return (0);
}
