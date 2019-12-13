/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/19 11:31:14 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

t_tet		*maintet(char *s)
{
	t_tet	*head;
	t_tet	*tmp;
	int		i;
	int		c;

	i = 0;
	c = 1;
	head = NULL;
	while (s[i] && i < (int)ft_strlen(s))
	{
		if (!head)
		{
			head = ft_newtet(ft_add(&s[i]), ft_y(&s[i]), ft_x(&s[i]), c++);
			tmp = head;
		}
		else
		{
			tmp->next = ft_newtet(ft_add(&s[i]), ft_y(&s[i]), ft_x(&s[i]), c++);
			tmp = tmp->next;
		}
		i += 21;
	}
	return (head);
}

char			**ft_add(char *s)
{
	char 		**ho;
	char		*buf;
	int			sim;

	sim = 0;
	buf = ft_strnew(10);
	ho = ft_strsplit(ft_add_2(s, buf, sim), '\n');
	free(buf);
	buf = NULL;
	return (ho);
}

char			*ft_add_2(char *s, char *buf, int sim)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (s[i] && i < 20)
	{
		if ((sim = ft_search(&s[i])))
		{
			while (s[i] && s[i] != '\n')
			{
				if (s[i + 5] == sim || ((s[i + 10] == sim) && i + 10 < 20))
					buf[j++] = s[i];
				else if (s[i] == sim || s[i - 5] == sim || s[i - 10] == sim)
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
			i++;
		}
		else
			i += 5;
	}
	return (buf);
}

t_tet			*ft_newtet(char **s, int x, int y, int numb)
{
	t_tet		*tmp;

	tmp = (t_tet*)ft_memalloc(sizeof(t_tet));
	tmp->numb = numb;
	tmp->x = x;
	tmp->y = y;
	tmp->count = 0;
	tmp->cnt = 0;
	tmp->content = s;
	tmp->next = NULL;
	return (tmp);
}

int			prover(char *s)
{
	int		stop;
	int		i;

	i = 0;
	stop = 19;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			if (i != stop)
				return (-1);
			stop += 21;
		}
		i++;
	}
	if (s[i] == '\0')
	{
		if (s[i - 2] != '.' && s[i - 2] != '#')
		{

			return (-1);
		}
		if (i != stop + 1)
		{
//			printf("i - %d  stop - %d\n", i, stop);
			return (-1);
		}
	}
	return (0);
}
