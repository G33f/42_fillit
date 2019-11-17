/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/30 14:37:16 by tzenz            ###   ########.fr       */
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
		return (-1);
	head = maintet(s);
    return (0);
}
