/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:21:06 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/26 15:21:07 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

char        **addfield(char **before, int numb)
{
	char 	**field;
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
	field = ft_strsplitc(buf, '\n');
	if (before)
		field = ft_cpyptrn(field, before);
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (field);
}

int				ft_fieldlong(t_tet *head, int i)
{
	int 		count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	count *= 4;
	if (ft_sqrt(count) * ft_sqrt(count) < count)
		return (ft_sqrt(count) + 1 + i);
	else
		return (ft_sqrt(count) + i);
}

void			ft_print(t_tet *head)
{
	while (head)
	{
		printf("head->count - %zu  head->numb - %zu\n", head->count, head->numb);
		head = head->next;
	}
}

void			ft_cntminus(int x, int y, t_tet *head)
{
	while (head)
	{
/*		if (x == head->x)
			head->cnt = 0;
		else if (y == head->y)*/
			head->cnt = 0;
		head = head->next;
	}

}

t_tet			*ft_snum(int next, t_tet *head, t_tet *tmp)
{

	while (tmp)
	{
		while (tmp)
		{
//			printf("next - %d  tmp->y - %zu  tmp->count - %zu  tmp->cnt - %d\n", next, tmp->y, tmp->count, tmp->cnt);
			if (next == tmp->y && !tmp->count && !tmp->cnt)
			{
				ft_cntminus(0, tmp->y, head);
				return (tmp);
			}
			tmp = tmp->next;
		}
		next = (next - 1 > 0) ? next - 1 : 4;
		tmp = head;
	}
	return (0);
}

/*int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

	if (!ft_scount(head))
	{
		ft_putsstr(field);
		return (0);
	}
	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
	{
		next = buf->y;
//		buf->cnt++;
		return (-2);
	}
	if (next == -1)
	{
		next = buf->y;
		buf->cnt++;
	}
	else
	{
//		printf("buf->numb - %zu\n", buf->numb);
		ft_putsstr(field);
	}
	fc1(addfield(field, ft_fieldlong(head, 0)), next, head, head);
	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) != -2)
	{
		nmmn(field, head);
		ft_print(head);
		printf("next - %d\n", next);
		fc1(field, buf->y, head, head);
	}
	return (0);
}*/ 																				//fc1 рекурсия

/*int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

	while (ft_scount(head))
	{
		if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
			return (-2);

//		ft_print(head);
//		printf("\nnext - %d\n", next);
//		ft_putsstr(field);
	}
	return (0);
}*/ 																				//fc1 итер подбор по y

void			ft_canc(char **field, t_tet *tmp)
{
	char 		sim;
	int 		j;
	int 		m;
	int 		n;

	j = 0;
	m = 0;
	n = 0;
	while (tmp->content[0][j] == '.')
		j++;
	while (m < ft_countptr(field))
	{
		if (tmp->content[0][j] == field[m][n])
			field[m][n] = '.';
		if (field[m][n] == '\n')
		{
			n = 0;
			m++;
		} else
			n++;
	}
}

int				ft_scount(t_tet *tmp)
{
	while (tmp)
	{
		if (!tmp->next)
			return (tmp->numb);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_fcount(char **field)
{
	int 		count;
	int 		m;
	int 		n;

	count = 0;
	m = 0;
	n = 0;
	while (m < ft_countptr(field))
	{
		if (field[m][n] != '.' && field[m][n] != '\n')
			count++;
		if (field[m][n] == '\n')
		{
			n = 0;
			m++;
		}
		else
			n++;
	}
	return (count / 4);
}

int				ft_sfield(char **field, t_tet *tmp)
{
	int 		j;
	int 		m;
	int 		n;

	j = 0;
	m = 0;
	n = 0;
	while (tmp->content[0][j] == '.')
		j++;
	while (m < ft_countptr(field))
	{
		if (field[m][n] == tmp->content[0][j])
			return (1);
		if (field[m][n] == '\n')
		{
			n = 0;
			m++;
		}
		else
			n++;
	}
	return (0);
}

int				fc1(char **field, int count, t_tet *head, t_tet *tmp)
{
	ft_putsstr(field);
	ft_putchar('\n');
	if (count == ft_fcount(field))
	{
		ft_putsstr(field);
		printf("    STOP    ");
		return (0);
	}
	if (!(ft_sfield(field, tmp)))
	{
		if ((ft_write(field, tmp)) < 0)
			return (-2);
	}
	if ((fc1(field, count, head, tmp->next)) < 0)
	{
		ft_canc(field, tmp);
		ft_putsstr(field);
		ft_putchar('\n');
		if ((ft_write(field, tmp->next) < 0))
		{
			ft_putsstr(field);
			ft_putchar('\n');
			return (-2);
		}
		ft_putsstr(field);
		ft_putchar('\n');
		fc1(field, count, head, tmp);
		if (count != ft_fcount(field))
		{
			ft_canc(field, tmp->next);
			return (-2);
		}
	}
	return (2);
} 																						//fc1 рек new

void			algm(t_tet *head)
{
	t_tet *tmp;
	char **field;
	int count;


	count = 1;
	field = NULL;
	field = addfield(field, 6);
//	field = addfield(field, ft_fieldlong(head, 0));
	fc1(field, ft_scount(head), head, head);
/*	while (fc1(field, 1, head, head) < 0)
	{
		printf(" -- \n");
		field = addfield(field, ft_fieldlong(head, count++));
		tmp = head;
		while (tmp)
		{
			if (tmp->count)
				tmp->count = 0;
			tmp = tmp->next;
		}
	}*/
/*	while (head)
	{
		ft_putsstr(head->content);
		head = head->next;
	}*/
/*	while (head)
	{
		ft_write(field, head);
		head = head->next;
	}*/
	ft_putchar('\n');
	ft_putsstr(field);
}

/*
int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

//	ft_putsstr(field);
	if (!ft_scount(head))
	{
		ft_putsstr(field);
		return (0);
	}

	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
	{
		next = buf->y;
//		buf->cnt++;
		return (-2);
	}
	else if (next == -1)
	{
		next = buf->y;
		buf->cnt++;
	}
	fc1(addfield(field, ft_fieldlong(head, 0)), next, head, head);
	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) != -2)
	{
//		if (buf->count)
//			buf->count = 0;
//		ft_putsstr(field);
		printf("next - %d\n", next);
//		ft_putsstr(buf->content);
		fc1(field, buf->y, head, head);
	}
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (0);
}
*/