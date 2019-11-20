/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:36:28 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/16 11:51:21 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

t_gnl				*ft_newlist(int fd)
{
	t_gnl			*tmp;

	tmp = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	tmp->fd = fd;
	tmp->res = NULL;
	tmp->next = NULL;
	return (tmp);
}

char				*ch(char *res, char **line)
{
	char			*tmp;

	tmp = NULL;
	if (res)
		if ((tmp = ft_strchr(res, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(res);
			ft_strcpy(res, ++tmp);
		}
		else
		{
			*line = ft_strdup(res);
			while (*res)
			{
				*res = '\0';
				res++;
			}
		}
	else
		*line = ft_strnew(1);
	return (tmp);
}

int					get_line(const int fd, char **line, char **res)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	char			*leak;
	int				r;

	tmp = ch(*res, line);
	while (!tmp && (r = read(fd, buf, BUFF_SIZE)))
	{
		if (r < 0)
			return (-1);
		buf[r] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*tmp = '\0';
			*res = ft_strdup(++tmp);
		}
		leak = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(leak);
	}
	return (r || ft_strlen(*line)) ? 1 : 0;
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (line == 0 || fd < 0)
		return (-1);
	if (!head)
		head = ft_newlist(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_newlist(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->res));
}
