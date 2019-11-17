/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:07:22 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/15 12:04:52 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*st;
	size_t	i;
	size_t	j;

	i = 0;
	st = (char *)str;
	if (!(i = ft_strlen(to_find)))
		return (st);
	i = 0;
	while (st[i])
	{
		j = 0;
		while (st[i + j] == to_find[j])
		{
			if (!(to_find[j + 1]))
				return (st + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
