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

void	ft_matclean(char **cube, t_tet *tes, int leng)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (j < leng)
	{
		while (i < leng)
		{
			if (cube[j][i] == (char)(tes->numb - 1 + 'A'))
				cube[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
}

int		ft_put(t_tet *tes, char **cube, int i, int j)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < (int)tes->y)
	{
		while (n < (int)tes->x)
		{
			if (cube[j + m][i + n] == '.')
				cube[j + m][i + n] = tes->content[m][n];
			n++;
		}
		n = 0;
		m++;
	}
	return (1);
}

int		ft_build(t_tet *tes, char **cube, int leng)
{
	int	i;
	int	j;

	j = 0;
	if (!tes)
		return (1);
	while (j < (leng - ((int)tes->y - 1)))
	{
		i = 0;
		while (i < (leng - ((int)tes->x - 1)))
		{
			if (ft_check(tes, cube, i, j) == 1)
			{
				ft_put(tes, cube, i, j);
				if (!(ft_build(tes->next, cube, leng)))
					ft_matclean(cube, tes, leng);
				else
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
