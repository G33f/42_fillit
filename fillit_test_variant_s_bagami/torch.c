/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:54:50 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/18 18:30:40 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_far(tetrimino **head, char **cube)
{
	int i;

	i = lengt(head);
	while(cube != NULL)
	{
		cube = ft_generate(cube, i);
		if(cube == NULL)
		{
			return (NULL);
		}
		cube = ft_construct(cube, head)
		if (cube == NULL)
		{
			ft_matdel(cube, i);
			if (i > lengt(head))
				return (NULL);
			i++;
		}
		if(cube)
			return (cube);
	}
}

int		ft_torch(int fd)
{
	char	*s;
	char	buf[550];
	int		r;
	tetrimino *head;
	char	**cube

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
	if ((cube = ft_far(head, cube)) == NULL)
	{
		ft_putstr("memary error\n");
		return (-1);
	}
	ft_putmat(cube);
	ft_matdel(cube, leng(head));
	return (0);
}
