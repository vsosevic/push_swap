/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:54:04 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/20 15:54:23 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	search_endl(char **line, char **buf, int ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			(*line)[i] = '\0';
		i++;
	}
	i = 0;
	if (ret < BUFF_SIZE)
		(*buf)[ret] = 0;
	while (i < BUFF_SIZE)
	{
		if ((*buf)[i] == '\n')
		{
			while (++i < BUFF_SIZE)
				(*buf)[j++] = (*buf)[i];
		}
		i++;
	}
	while (j < BUFF_SIZE)
		(*buf)[j++] = 0;
}

static void	inner_realloc(char **line)
{
	char *str;

	if (line)
	{
		str = ft_strnew(ft_strlen(*line));
		ft_strcpy(str, *line);
		ft_memdel((void **)line);
		*line = ft_strnew(ft_strlen(str) + BUFF_SIZE);
		ft_strcpy(*line, str);
		free(str);
	}
}

static int	ret_minus_one(int fd, char **line, char ***buf)
{
	if (fd < 0 || read(fd, buf, 0) || !line)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (*buf == NULL)
		if (!(*buf = (char **)malloc(sizeof(char *) * (FD))))
			return (-1);
	return (0);
}

static int	endl_found(char **buf, char **line, int fd)
{
	if (ft_memchr(buf[fd], '\n', BUFF_SIZE))
	{
		search_endl(line, &buf[fd], BUFF_SIZE);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	**buf;
	int			ret;

	if (ret_minus_one(fd, &(*line), &buf) == -1)
		return (-1);
	if (buf[fd] != NULL)
	{
		ft_strcpy(*line, buf[fd]);
		if (endl_found(buf, line, fd) == 1)
			return (1);
	}
	buf[fd] = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf[fd], BUFF_SIZE)))
	{
		inner_realloc(&(*line));
		ft_strncat(*line, buf[fd], ret);
		if (ft_strrchr(buf[fd], '\n'))
			break ;
	}
	search_endl(line, &buf[fd], ret);
	if (ret == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
