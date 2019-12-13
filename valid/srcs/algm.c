/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:58:29 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/22 14:58:30 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int				ft_write(char **field, t_tet *tmp)
{
	int			m;
	int			n;

	m = 0;
	n = 0;
	while (field[m] && field[m][n])
	{
		if (tmp->x == ft_countx(tmp->content, m, &n, field))
		{
			ft_humhum(field, tmp->content, m, n);
			tmp->count++;
			return (ft_s(m, n, tmp->x, field));
		}
//		else if (ft_countx(tmp->content, m, &n, field) == -1)
//			return (-1);
		if (field[m][n] == '\n')
		{
			m++;
			n = 0;
		}
		else
			n++;
	}
	return (-1);
}

int				ft_countx(char **content, int m, int *n, char **field)
{
	int 		count;
	int			j;

	j = 0;
	while (field[m][*n] != '\n' && field[m][*n])
	{
		while ((content[0][j] != field[m][*n] && content[0][j] == '.') ||
				(content[0][j] != field[m][*n] && field[m][*n] == '.') ||
				(content[0][j] == '.' && field[m][*n] == '.'))
		{
			if (j + 1 == (int)(ft_strlen(content[0])) && field[m][*n] != '\n')
			{
				if ((count = ft_county(content, m, *n - j, field)))
				{
					*n = *n - j;
					return ((count < 0) ? count : j + 1);
				}
			}
			j++;
			*n += 1;
		}
		*n = (*n - j) + 1;
		j = 0;
	}
	return (0);
}

int				ft_county(char **content, int m, int n, char **field)
{
	int			i;
	int			j;
	int			count;

	count = m;
	i = 0;
	j = 0;
	while ((content[i][j] != field[m][n] && content[i][j] == '.') ||
			(content[i][j] != field[m][n] && field[m][n] == '.') ||
			(content[i][j] == '.' && field[m][n] == '.'))
	{
		m++;
		if (++i == ft_countptr(content))
		{
			if (j + 1 == (int)ft_strlen(*content))
				return (j + 1);
			i = 0;
			m = count;
			n++;
			j++;
		}
		if (m == ft_countptr(field))
			return (0);
	}
	return (0);
}

void			ft_humhum(char **field, char **content, int m, int n)
{
	int			count;
	int			i;
	int			j;

	i = 0;
	j = 0;
	count = n;
	while (content[i])
	{
		if (content[i][j] != '.' && content[i][j])
			field[m][n++] = content[i][j++];
		else if (content[i][j++] == '.')
			n++;
		else
		{
			m++;
			i++;
			n = count;
			j = 0;
		}
	}
}

int				ft_s(int m, int n, int x, char **field)
{
	int			count;

	count = 0;
	n = n + x;
	while (field[m][n] != '.' && field[m][n])
	{
		if (field[m][n] == '\n' && field[m + 1])
			while (field[m][n] == '\n' && field[m + 1])
			{
				n = 0;
				m++;
			}
		else
			n++;
	}
	if (field[m][n - 1] == '.')
		count++;
	while (field[m][n++] == '.')
		count++;
	return (count > 4) ? 4 : count;
}

/*
 * int				ft_write(char **field, int x, char **content)
{
	int			m;
	int			n;

	m = 0;
	n = 0;
	while (field[m] && field[m][n])
	{
		if (x == ft_countx(content, m, &n, field))
		{
			ft_humhum(field, content, m, n);
			return (ft_s(m, n, x, field));
		}
		if (field[m][n] == '\n')
		{
			m++;
			n = 0;
		}
		else
			n++;
	}
	return (-1);
}
 *
 *
 * int				maxnumb(t_tet *head)
{
	int 		count;

	count = 1;
	while (head != NULL)
	{
		if (!head->count)
			count++;
		head = head->next;
	}
while (head->next != NULL)
{
count++;
head = head->next;
}
return (count);
}

int				ft_searchcount(t_tet *tmp, int next)
{
	int 		count;

	count = 0;
	while (tmp != NULL)
	{
		if (tmp->numb == next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char			**poisk(t_tet *head, int next)
{
	while (head != NULL)
	{
		if (head->numb == next)
			break;
		head = head->next;
	}
	if (head->count > 0)
		head->count -= head->count;
	else
		head->count++;
//	printf("1 count - %zu\n",head->count);
	return (head->content);
}

int				huk(char **field)
{
	char 		sim;
	int 		count;
	int 		i = 0;
	int 		j = 0;

	sim = 'A';
	count = 0;
	while (field[i])
	{
		while (field[i][j] != '\n')
		{
			if (field[i][j] == sim)
			{
				count++;
				sim++;
			}
			j++;
		}
		i++;
		j = 0;
	}
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (count);
}

 */