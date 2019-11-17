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
			head = ft_newtet(ft_add(&s[i]), ft_x(&s[i]), ft_y(&s[i]),  count);
			tmp = head;
		}
		else
		{
			tmp->next = ft_newtet(ft_add(&s[i]), ft_x(&s[i]), ft_y(&s[i]),count);
			tmp = tmp->next;
		}
		i += 21;
	}
	return (head);
}

tetrimino   *ft_newtet(char *s, int	x, int y, int	numb)
{
	tetrimino   *tmp;

	tmp = (tetrimino*)ft_memalloc(sizeof(tetrimino));
	tmp->numb = numb;
	tmp->x = x;
	tmp->y = y;
	tmp->content = s;
	tmp->next = NULL;
	return (tmp);

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
	return (buf);
}