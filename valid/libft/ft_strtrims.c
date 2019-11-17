/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrims.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:35:12 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/21 11:14:22 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strtrims(char const *s)
{
	char	*st;
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	st = (char *)s;
    if (!ft_strchr(s, '#'))
    {
        new = NULL;
        return (new);
  	}
	while (*st == '.')
		st++;
	len = ft_strlen(st) - 1;
	while (st[len] == '.')
		len--;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	while (i <= len)
	{
		new[i] = st[i];
		i++;
	}
	return (new);
}
