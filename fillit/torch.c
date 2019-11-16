/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:54:50 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/14 20:54:53 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int	main()
{
	char		**cube;
	tetrimino	*tes;
	int			i;
	int			res;

	/*test(*tes);*/
	res = 0;
	i = lengt(tes);
	while (res != 1)
	{
		if (!(generate(&cube, i))
		{
			ft_putstr("error\n");
			return 0;
		}
		res = construct(tes, &cube);
		if (res == -1)
		{
			ft_matdel(cube, i);
			ft_putstr("error\n");
			return (0);
		}
		i++;
	}
	ft_putmat(cube);
	ft_matdel(cube);
	return (0);
}
