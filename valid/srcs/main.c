/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/19 14:03:51 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int		main(void)
{
	char	*s;
	char	buf[550];
	int		fd;
	int		r;
	tetrimino *head;

	fd = open("test", O_RDONLY);
	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);

	if (valid(&s) < 0)
	{
		ft_putstr("0\n");
		return (-1);
	}
	head = maintet(s);
/*	while (head->next != NULL)
	{
		ft_putsstr(head->content);
		printf("x - %zu y - %zu numb - %zu\n", head->x, head->y, head->numb);
		head = head->next;
	}
	ft_putsstr(head->content);
	printf("x - %zu y - %zu numb - %zu\n", head->x, head->y, head->numb);*/
	return (0);
}
