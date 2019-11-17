/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:06:21 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/21 11:14:03 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	char	*st;
	char	ret;

	st = (char *)s;
	ret = (char)ch;
	if (ret == '\0')
	{
		while (*st)
			st++;
		return (st);
	}
	while (*st)
	{
		if (*st == ret)
			return (st);
		st++;
	}
	return (NULL);
}
