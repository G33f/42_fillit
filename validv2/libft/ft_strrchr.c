/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:24:40 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/17 19:22:06 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char	ret;
	char	*st;
	int		i;

	st = (char *)s;
	ret = (char)ch;
	i = ft_strlen(st) - 1;
	st = &st[i];
	if (ret == '\0')
	{
		while (*st)
			st++;
		return (st);
	}
	while (st >= s)
	{
		if (*st == ret)
			return (st);
		st--;
	}
	return (NULL);
}
