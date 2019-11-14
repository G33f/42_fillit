/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:30:43 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/12 16:30:47 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		put(tetrimino tes, char ***cube, i, j)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < tes->y)
	{
		while (n < tes->x)
		{
			coub[j + m][i + n] = tes->content[m][n];
		}
		n = 0;
		m++;
	}
}

int			**construct(tetrimino tes, char ***cube)
{
	char	**step;
	int		i;
	int		j;
	int		leng;

	i = 0;
	j = 0;
	if(!tes)
		return (1);
	leng = ft_strlen(cube[0]);
	if (!(generate(&step, leng)))
		return (-1);
	ft_matcp(step, cube, leng, leng);
	while (j < (leng - tes->y))
	{
		while (i < (leng - tes->x))
		{
			if (!(checker(step, tes,i , j)))
				i++;
			else
			{
				put(tes, step, i, j);
				i = construct(tes->next, step);
				if (i == -1 || !i)
					ft_matdel(step, leng);
				return (i);
			}
		}
	}
}

int		checker(tetrimino tes, char **cube, int i, int j)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m < tes->y)
	{
		while (n < tes->x)
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

int			generate(char ***cube, int i)
{
	int 	r;
	char	*line;

	r = 0;
	if (!(*cube = malloc(sizeof(i))))
	{
		return (0);
	}
	while(r < i)
	{
		if(!(cube[r] = malloc(sizeof(i + 1))))
		{
			ft_matdel(cube, i);
			return (0);
		}
		r++;
	}
	r = 0;
	while(r < i)
	{
		*cube[r] = ft_memset(cube[r], '.', i);
		cube[r][i + 1] = '\n';
		r++;
	}
	return (1);
}
