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

/*char	**construct(tetrimino tes, char ***cube)
{
	while()
}*/

int	lengt(tetrimino *tes)
{
	int i;

	if (((int)ft_sqrt(tes->numb) * (int)ft_sqrt(tes->numb)) < i)
		i = ((int)ft_sqrt(tes->numb) + 1);
	else
		i = ((int)ft_sqrt(tes->numb));
	return (i);
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

int	main()
{
	char		**cube;
	tetrimino	*tes;

	/*tes = test();*/
	if (!(generate(&cube, lengt(tes))))
	{
		ft_putstr("error\n");
		return 0;
	}
	return 0;
}
