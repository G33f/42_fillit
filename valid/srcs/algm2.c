/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:21:06 by tzenz             #+#    #+#             */
/*   Updated: 2019/12/10 10:41:25 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

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

int				fc1(char **field, t_tet *head)
{
	while (head != NULL)
	{
		if (!head->count)
		{
			if ((ft_write(field, head->x, head->content)) == 0)
				return (-1);
			head->count++;
		}
		head = head->next;
	}
	return (0);
}


void			algm(t_tet *head)
{
	char		**field;
	int 		count;

	count = 1;
	field = NULL;
	field = addfield(field, ft_fieldlong(head, 0));
	while (fc1(field, head) < 0)
		field = addfield(field, ft_fieldlong(head, count++));
	ft_putsstr(field);
}
