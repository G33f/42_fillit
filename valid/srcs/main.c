/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/30 14:37:16 by tzenz            ###   ########.fr       */
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
	while (head->next != NULL)
	{
		printf("%s\nx - %zu y - %zu numb - %zu\n", *head->content, head->x, head->y, head->numb);
		head = head->next;
	}
	printf("%s\nx - %zu y - %zu numb - %zu\n", *head->content, head->x, head->y, head->numb);
	return (0);
}

/*
char   *ft_add(char *s)
{
	char	**ho;
	char	*buf;
	int		sim;
	int		i;
	int		j;

	buf = ft_strnew(10);
	j = 0;
	i = 0;
	sim = 0;
	while (s[i] && i < 20)
	{
		while (s[i] && s[i] != '\n')
		{
			if (s[i] != '.')
				sim = s[i];
			i++;
		}
		if (sim)
		{
			i -= 4;
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
		i++;
	}
	ho = ft_strsplit(buf, '\n');
	return (ho);
}*/