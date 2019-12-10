/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:50 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/13 10:24:44 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int			valid(char **s)
{
	char	sim;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (vone(*s, &count) < 0 || prover(*s) < 0)
		return (-1);
	sim = 'A';
	while (s[0][i] && i < (int)ft_strlen(&s[0][0]))
	{
		if (vtwo(&s[0][i], sim++) < 0)
			return (-1);
		i += 21;
	}
	return (0);
}

int			vone(char *s, int *count)
{
	int		i;
	int		m;

	i = 0;
	m = 5;
	while (s[i] && i < (m - 1))
	{
		while (s[i] != '\n' && s[i])
		{
			if ((s[i] != '#' && s[i] != '.') || i >= (m - 1))
				return (-1);
			if (s[i++] == '#')
				*count += 1;
		}
		if (ft_one(s, i, &m, count) < 0 || i++ > 545)
			return (-1);
	}
	return (0);
}

int			ft_one(char *s, int i, int *m, int *count)
{
	if (i < (*m - 1) && s[i - 1] != '\n')
		return (-1);
	if (s[i] != '\0' && s[i - 1] != '\n')
		*m = *m + 5;
	if ((s[i] == '\n' && s[i + 1] == '\n') || s[i] == '\0')
	{
		if (*count != 4)
			return (-1);
		*count = 0;
		*m += 1;
	}
	return (0);
}

int			vtwo(char *s, char sim)
{
	int		count;
	int		e;
	int		i;

	count = 0;
	i = 0;
	e = 0;
	while (s[i] != '#' && s[i])
		i++;
	e = i;
	while ((s[e + 1] == '#') || (s[e + 5] == '#' || s[e] == '#'))
	{
		s[e] = sim;
		count++;
		i = e;
		ft_two(s, &i, &count, &sim);
		e++;
	}
	return ((count != 4)) ? -1 : 0;
}

void		ft_two(char *s, int *i, int *count, char *sim)
{
	int		j;

	while (s[*i + 5] == '#' && *i + 5 < 20)
	{
		*i += 5;
		j = *i;
		while (s[j + 1] == '#')
		{
			j++;
			s[j] = *sim;
			*count += (s[j + 5] == '#' && j + 5 < 20) ? 2 : 1;
			s[j + 5] = (s[j + 5] == '#' && j + 5 < 20) ? *sim : s[j + 5];
		}
		j = *i;
		while (s[j - 1] == '#')
		{
			j -= 1;
			s[j] = *sim;
			*count += (s[j + 5] == '#' && j + 5 < 20) ? 2 : 1;
			s[j + 5] = (s[j + 5] == '#' && j + 5 < 20) ? *sim : s[j + 5];
		}
		s[*i] = *sim;
		*count += 1;
	}
}
