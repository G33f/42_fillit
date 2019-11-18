/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/18 18:25:11 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int		main(void)
{
	char	*s;
	char	buf[550];
	int		fd;
	int		r;
	tetrimino *head;

	fd = open("test", O_RDONLY);
	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);

	if (valid(&s) < 0)
	{
		ft_putstr("0\n");
		return (-1);
	}
	head = maintet(s);
	return (0);
}

/*
	while (head->next != NULL)
	{
		printf("%s\nx - %zu y - %zu\n", *head->content, head->x, head->y);
		head = head->next;
	}
	printf("%s\nx - %zu y - %zu\n", *head->content, head->x, head->y);

 tetrimino	*maintet(char *s)
{
	tetrimino	*head;
	tetrimino	*tmp;
	int			i;
	int 		count;
	int 		stop;

	i = 0;
	count = 1;
	head = NULL;
	stop = ft_strlen(s);
	while (s[i] && i < stop)
	{
		if (!head)
		{
			head = ft_newtet(ft_add(&s[i]), count);
			tmp = head;
		} else
		{
			tmp->next = ft_newtet(ft_add(&s[i]), ++count);
			tmp = tmp->next;
		}
		i += 21;
	}
	return (head);
}

char   *ft_add(char *s)
{
	char 	*buf;
	int 	sim;
	int     i;
	int 	j;

	buf = ft_strnew(10);
	j = 0;
	i = 0;
	sim = 0;
	while (s[i] && i < 20)
	{
		if ((sim = ft_search(&s[i])))
		{
			printf("%c\n", sim);
			while (s[i] && s[i] != '\n')
			{
				if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
					buf[j++] = s[i];
				else if (s[i - 5] == sim || s[i - 10] == sim)
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
			sim = 0;
		}
		else
			i += 4;
		i++;
	}
//	ft_putstr(buf);
	return (buf);
}

int		ft_search(char *s)
{
	int sim;
	int i;
	i = 0;

	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '.')
			sim = s[i];
		i++;
	}
	return (sim);
}*/
