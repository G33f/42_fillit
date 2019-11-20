/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:11:00 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/09 15:25:35 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if ((tmp = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (!content)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if (!(tmp->content = ft_memalloc(content_size)))
			{
				free(tmp);
				return (NULL);
			}
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
