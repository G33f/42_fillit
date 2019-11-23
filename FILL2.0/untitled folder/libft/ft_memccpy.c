/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:37:02 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/13 11:59:37 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n--)
	{
		*s1++ = *s2++;
		if (*(s1 - 1) == ch)
			return (s1);
	}
	return (NULL);
}
