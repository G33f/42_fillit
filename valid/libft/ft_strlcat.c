/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:52:05 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/16 19:05:20 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	i = 0;
	j = 0;
	d = 0;
	s = 0;
	while (src[s])
		s++;
	i = ft_strlen(dest);
	if (size < i)
		return (size + s);
	while (dest[d])
		d++;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j > 0)
		dest[i] = '\0';
	return (d + s);
}
