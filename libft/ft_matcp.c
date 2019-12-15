/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matcp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:56:52 by wpoudre           #+#    #+#             */
/*   Updated: 2019/12/15 12:39:37 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_matcp(void **d, const void **s, size_t n1, size_t n2)
{
	unsigned char	**str1;
	unsigned char	**str2;
	size_t			i;
	size_t			j;

	str1 = (unsigned char **)d;
	str2 = (unsigned char **)s;
	if (!s && !d)
		return (NULL);
	i = 0;
	j = 0;
	if (n1 <= 0 || n2 <= 0)
		return (d);
	while (i < n1)
	{
		while (j < n2)
		{
			str1[i][j] = str2[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (d);
}
