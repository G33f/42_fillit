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

int			ft_check(t_tet *tes, char **cube, int i, int j)
{
	int		m;
	int		n;

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

char		**ft_newmat(int numb)
{
	char	**field;
	char	buf[numb * (numb + 1)];
	int		ins;
	int		i;

	i = 0;
	ins = numb;
	while (i < numb * (numb + 1))
	{
		if (i == ins)
		{
			buf[i] = '\n';
			ins += numb + 1;
		}
		else
			buf[i] = '.';
		i++;
	}
	buf[i] = '\0';
	field = ft_strsplit(buf, '\n');
	return (field);
}

int			ft_logic(t_tet *tes)
{
	char	**cube;
	int		i;

	i = ft_lengt(tes);
	while (i <= (ft_lengt(tes) + 1))
	{
		if (!(cube = ft_newmat(i)))
			return (0);
		if (!(ft_build(tes, cube, i)))
			ft_fielddel(cube, i++);
		else
		{
			ft_putmat((const char **)cube);
			ft_fielddel(cube, i);
			return (1);
		}
	}
	return (0);
}

int			ft_lengt(t_tet *tes)
{
	int		i;

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
	return (i);
}

int			ft_starter(int fd)
{
	char	*s;
	char	buf[550];
	int		r;
	t_tet	*head;

	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (ft_valid(&s) < 0)
	{
		free(s);
		return (0);
	}
	head = ft_maintet(s);
	free(s);
	if (!(ft_logic(head)))
	{
		ft_freetet(head);
		return (0);
	}
	ft_freetet(head);
	return (1);
}
