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

int		ft_check(t_tet *tes, char **cube, int i, int j)
{
	int	m;
	int	n;

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

char	    **ft_newmat(int i, int r)
{
	char	*str;
	char 	*buf;
	char	*tmp;
	char	**cube;

	if(!(str = ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	ft_memset(str, '.', i);
	str[i] = '\n';
	buf = str;
	while (r < i)
	{
		tmp = buf;
		if (!(buf = ft_strjoin(buf, str)))
		{
			free(buf);
			free(str);
			return (NULL);
		}
		if (r > 1)
			free(tmp);
		r++;
	}
	cube = ft_strsplit(buf, '\n');
	free(str);
	free(buf);
	return (cube);
}


int			ft_logic(t_tet *tes)
{
	char	**cube;
	int		i;

	i = lengt(tes);
	while (i <= (lengt(tes) + 1))
	{
		if (!(cube = ft_newmat(i, 1)))
			return (0);
		if (!(ft_build(tes, cube, i)))
		{
			ft_matdel((void **) cube, i);
			i++;
		}
		else
		{
			ft_putmat((const char **) cube);
			ft_matdel((void **) cube, i);
			return (1);
		}
	}
	return (0);
}

int		lengt(t_tet *tes)
{
	int i;

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

int		ft_starter(int fd)
{
	char		*s;
	char		buf[550];
	int			r;
	t_tet	*head;

	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0)
		return (0);
	head = maintet(s);
	free(s);
	if (!(ft_logic(head)))
		return (0);
	return (1);
}
