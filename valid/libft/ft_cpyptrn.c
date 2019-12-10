/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyptrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:44:03 by tzenz             #+#    #+#             */
/*   Updated: 2019/12/04 15:44:05 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

char		**ft_cpyptrn(char **field, char **before)
{
	int		i;
	int		j;
	int		m;
	int		n;

	i = 0;
	j = 0;
	m = 0;
	n = 0;
	while (before[m])
	{
		while (before[m][n] != '\n')
			field[i][j++] = before[m][n++];
		i++;
		m++;
		j = 0;
		n = 0;
	}
	return (field);
}
