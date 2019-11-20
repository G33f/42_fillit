/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matcp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:56:52 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/14 20:56:54 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_matcp(char **mat1, char **mat2, int mt1_l, int mt2_l)
{
	int i;
	int j;

	if (!mat1 || !mat2 || (mt1_l != mt2_l) || (!mt1_l))
		return ;
	i = 0;
	j = 0;
	while (j < mt1_l)
	{
		while(i < mt2_l)
		{
			mat1[j][i] = mat2[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	char (mat1);
}
