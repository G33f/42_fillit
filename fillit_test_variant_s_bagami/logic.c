/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:30:43 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/18 18:29:56 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	put(tetrimino **tes, char **cube, int i,int j)
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

char		**ft_construct(tetrimino **tes, char **cube)
{
	char	**step;
	int		i;
	int		j;
	int		leng;

	j = 0;
	if(!tes)
		return (cube);
	leng = ft_strlen(cube[0]);
	if (!(step = ft_generate(step, leng)))
		return (NULL);
	ft_matcp(step, cube, leng, leng + 1);
	while (j < (leng - tes->y))
	{
		i = 0;
		while (i < (leng - tes->x))
		{
			if (checker(step, tes,i , j) == 1)
			{
				put(tes, step, i, j);
				if (!(cube = ft_construct(tes->next, step)))
				{
					ft_matdel(step, leng);
					if (!(step = ft_generate(step, leng)))
						return (NULL);
				}
				else
				{
					ft_matcp(cube, step, leng, leng + 1);
					ft_matdel(step, leng);
					return (cube);
				}
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

int		checker(tetrimino **tes, char **cube, int i, int j)
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

char		**ft_generate(char **cube, int i)
{
	int 	r;
	char	*line;

	r = 0;
	if (!(*cube = malloc(sizeof(i))))
	{
		return (NULL);
	}
	while(r < i)
	{
		if(!(cube[r] = malloc(sizeof(i + 1))))
		{
			ft_matdel(cube, i);
			return (NULL);
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
	return (cube);
}
