/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:18:45 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/26 15:48:10 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;
	unsigned char	i;

	st = (unsigned char *)s;
	i = (unsigned char)c;
	while (n--)
	{
		if (*st == i)
			return (st);
		st++;
	}
	return (NULL);
}
