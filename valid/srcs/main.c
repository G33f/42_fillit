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

int		main(int argc, char **argv)
{
	t_tet 	*head;
	char	buf[550];
	char	*s;
	int		fd;
	int		r;

	fd = open(argv[1], O_RDONLY);
	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0 || argc != 2)
	{
		ft_putstr("error\n");
		exit (EXIT_SUCCESS);
		return (0);
	}
	head = maintet(s);
	algm(head);
/*	while (head != NULL)
	{
		ft_putsstr(head->content);
		printf("x - %zu y - %zu numb - %zu\n", head->x, head->y, head->numb);
		head = head->next;
	}*/
	return (0);
}


/*
int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
   int			count;
   int 		random;

   random = 4;
   count = maxnumb(head);
   while (tmp != NULL)
   {
	   while (tmp != NULL)
	   {
		   if ((int)tmp->x == next && !tmp->count)
			   break;
		   tmp = tmp->next;
	   }
	   if (!tmp)
	   {
		   random = (random - 1 < 1) ? 4 : random - 1;
		   next = random;
		   tmp = head;
	   }
//		printf("count - %d  numb - %zu  next - %d  tmp->count - %zu\n", count, tmp->numb, next, tmp->count);
	   if ((int)tmp->x == next && !tmp->count)
	   {
		   if ((next = ft_write(field, tmp->x, tmp->content)) > 0)
		   {
			   count--;
			   tmp->count++;
		   }
		   else
			   return (-1);
	   }
	   tmp = head;
	   if (!count)
		   return (0);
   }
   return (0);
}
 *void			fc1(int next, char **field, t_tet *head, t_tet *tmp)
{
   int 		count;

   count = 0;
   if (tmp == NULL)
   {
	   tmp = head;
	   while (tmp->next != NULL)
	   {
		   if (tmp->count)
			   count++;
		   tmp = tmp->next;
	   }
	   printf("next - %d  count - %d  tmp->numb - %zu\n", next, count, tmp->numb);
	   if (++count == tmp->numb)
		   return;
	   else
		   fc1(next, field, head, (tmp = head));
   }
   else if (next == tmp->x && !tmp->count)
   {
	   tmp->count++;
	   fc1(ft_write(field, tmp->x, tmp->y, tmp->content), field, head, tmp->next)'

   }
   else
	   fc1(next, field, head, tmp->next);
}

*/