/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:35:44 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/20 04:35:47 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(tetrimino *tes, char **cube, int i, int j)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m < (int)tes->y)
	{
		while (n < (int)tes->x)
		{
			if ((cube[j + m][i + n] == '.') || (tes->content[m][n] == '.'))
				n++;
			else
				return (0);
		}
		n = 0;
		m++;
	}
	return (1);
}

char	**ft_newmat(char **cube, int i)
{
	int 	r;

	r = 0;
	if (!(*cube = malloc(sizeof(i))))
	{
		return (NULL);
	}
	while(r < i)
	{
		if(!(cube[r] = malloc(sizeof(i + 1))))
		{
			ft_matdel((void**)cube, i);
			return (NULL);
		}
		r++;
	}
	r = 0;
	while(r < i)
	{
		*cube[r] = (char)ft_memset(cube[r], '.', i);
		cube[r][i + 1] = '\n';
		r++;
	}
	return (cube);
}


int			ft_logic(tetrimino *tes)
{
	char	**cube;
	int		i;

	i = lengt(tes);
	while(i < (lengt(tes) + 1))
	{
		cube = ft_newmat(cube, i);
		if (cube == NULL)
			return (0);
		cube = ft_build(tes, cube, i);
		if (cube == NULL)
		{
			ft_matdel((void**)cube, i);
			i++;
		}
		else
		{
			ft_putmat((const char**)cube);
			ft_matdel((void**)cube, i);
			return (1);
		}
	}
	return (0);
}

int		lengt(tetrimino *tes)
{
	int i;

	i = tes->numb * 4;
	if (((int)ft_sqrt(i) * (int)ft_sqrt(i)) < i)
		i = ((int)ft_sqrt(i) + 1);
	else
		i = ((int)ft_sqrt(i));
	return (i);
}

int		ft_starter(int fd)
{
	char		*s;
	char		buf[550];
	int			r;
	tetrimino	*head;

	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0)
		return (0);
	head = maintet(s);
	if (!(ft_logic(head)))
		return (0);
	return (1);
}
