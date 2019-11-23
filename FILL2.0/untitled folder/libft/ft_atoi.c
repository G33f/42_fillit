/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:01:04 by exam              #+#    #+#             */
/*   Updated: 2019/09/23 10:43:55 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	unsigned long	y;
	size_t			i;
	int				z;

	res = 0;
	i = 0;
	z = 1;
	y = (unsigned long)(FT_LONG_MAX / 10);
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	z = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((res > y || (res == y && (str[i] - '0') > 7)) && z == 1)
			return (-1);
		if ((res > y || (res == y && (str[i] - '0') > 8)) && z == -1)
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * z));
}
