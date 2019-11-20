/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 06:41:33 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/20 06:41:37 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_put(tetrimino *tes, char **cube, int i, int j)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < (int)tes->y)
	{
		while (n < (int)tes->x)
		{
			cube[j + m][i + n] = tes->content[m][n];
		}
		n = 0;
		m++;
	}
	return (cube);
}

char		**ft_build(tetrimino *tes, char **cube, int leng)
{
	char	**step;
	int		i;
	int		j;

	j = 0;
	if(!tes)
		return (cube);
	if (!(step = ft_newmat(step, leng)))
		return (NULL);
	ft_matcp(step, cube, leng, leng + 1);
	while (j < (leng - (int)tes->y))
	{
		i = 0;
		while (i < (leng - (int)tes->x))
		{
			if (ft_check(tes, cube,i , j) == 1)
			{
				step = ft_put(tes, step, i, j);
				if (!(cube = ft_build(tes->next, step, leng)))
				{
					ft_matdel(step, leng);
					if (!(step = ft_newmat(step, leng)))
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
