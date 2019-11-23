/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:46:48 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/18 10:22:49 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char	*)dest;
	while (count < n)
	{
		str[count] = c;
		count++;
	}
	return (dest);
}
