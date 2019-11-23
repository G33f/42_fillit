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
	while (m < (int)tes->x)
	{
		while (n < (int)tes->y)
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

char	    **ft_newmat(int i)
{
	char    **cube;
	int		r;

	r = 0;
	if (!(cube = malloc(sizeof(char*) * (i + 1))))
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
	cube[r] = malloc(sizeof(1));
	cube[r][0] = '\0';
	r = 0;
	while(r < i)
	{
		ft_memset(cube[r], '.', i);
		ft_putmat((const char**)cube);
		r++;
	}
	//ft_putmat((const char**)cube);
	return (cube);
}


int			ft_logic(tetrimino *tes)
{
	char	**cube;
	int		i;

	i = lengt(tes);
	while (i < (lengt(tes) + 1))
	{
		if (!(cube = ft_newmat(i)))
			return (0);
		//ft_putmat((const char**)cube);
		if (!(ft_build(tes, cube, i)))
		{
			//ft_matdel((void **) cube, i);
			i++;
		}
		else
		{
			//ft_putmat((const char **) cube);
			//ft_matdel((void **) cube, i);
			return (1);
		}
	}
	return (0);
}

int		lengt(tetrimino *tes)
{
	int i;
	//tetrimino *res;

	//res = tes;
	i = 0;
	while (tes)
	{
		i++;
		tes = tes->next;
	}
	i = i * 4;
	if (((int)ft_sqrt(i) * (int)ft_sqrt(i)) < i)
		i = ((int)ft_sqrt(i) + 1);
	else
		i = ((int)ft_sqrt(i));
	//tes = res;
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
	/*while (head != NULL)
	{
		ft_putmat((const char**)head->content);
		head = head->next;
	}*/
	if (!(ft_logic(head)))
		return (0);
	return (1);
}
