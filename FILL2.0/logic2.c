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

int		ft_put(tetrimino *tes, char **cube, int i, int j)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < (int)tes->x)
	{
		while (n < (int)tes->y)
		{
			cube[j + m][i + n] = tes->content[m][n];
		}
		n = 0;
		m++;
	}
	return (1);
}

int			ft_build(tetrimino *tes, char **cube, int leng)
{
	char	**step;
	int		i;
	int		j;

	j = 0;
	if(!tes)
		return (1);
	if (!(step = ft_newmat(leng)))
		return (0);
	ft_putmat((const char **)step);
/*	ft_matcp((void**)step, (const void**)cube, leng + 1, leng + 1);
	while (j < (leng - (int)tes->x))
	{
		i = 0;
		while (i < (leng - (int)tes->y))
		{
			if (ft_check(tes, cube,i , j) == 1)
			{
				ft_put(tes, step, i, j);
				if (!(ft_build(tes->next, step, leng)))
				{
					ft_matdel((void**)step, leng);
					if (!(step = ft_newmat(leng)))
						return (0);
				}
				else
				{
					ft_matcp((void**)cube, (const void**)step, leng, leng + 1);
					ft_matdel((void**)step, leng);
					return (1);
				}
			}
			i++;
		}
		j++;
	}*/
	return (1);
}
