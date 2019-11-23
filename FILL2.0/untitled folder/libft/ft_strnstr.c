/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:56:08 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/15 12:04:54 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t size)
{
	char	*st;
	size_t	findl;
	size_t	j;
	size_t	i;

	st = (char *)str;
	if (!(findl = ft_strlen(find)))
		return (st);
	if (ft_strlen(str) < findl || size < findl)
		return (NULL);
	i = 0;
	while (st[i] && i <= size - findl)
	{
		j = 0;
		while (st[i + j] == find[j] && find[j])
		{
			if (!(find[j + 1]))
				return (st + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
