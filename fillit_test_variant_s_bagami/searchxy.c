/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchxy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:35:47 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/15 17:35:48 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_search(char *s)
{
	int sim;
	int i;

	sim = 0;
	i = 0;
	while (i < 4)
	{
		if (s[i] != '.')
			sim = s[i];
		i++;
	}
	return (sim);
}

int		ft_x(char *s)
{
	int flag;
	int i;
	int x;

	x = 0;
	i = 0;
	flag = 0;
	while (i < 20)
	{
		while (i < 20 && s[i] != '\n')
		{
			if (s[i] != '.' && s[i] != '\0' && !flag)
			{
				flag = 1;
				x++;
			}
			i++;
		}
		flag = 0;
		i++;
	}
	return (x);
}

int		ft_y(char *s)
{
	int	i;
	int y;
	int max;

	max = 0;
	i = 0;
	y = 0;
	while (i < 20)
	{
		if (ft_search(&s[i]))
		{
			while (i < 20 && s[i] != '\n')
			{
				if (s[i] != '.' || (s[i + 5] != '.' && i + 5 < 20))
					y++;
				i++;
			}
			max = (max < y) ? y : max;
			y = 0;
		}
		else
			i += 4;
		i++;
	}
	return (max);
}

int		lengt(tetrimino **tes)
{
	int i;

	i = tes->numb * 4;
	if (((int)ft_sqrt(i) * (int)ft_sqrt(i)) < i)
		i = ((int)ft_sqrt(i) + 1);
	else
		i = ((int)ft_sqrt(i));
	return (i);
}