/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:00:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/12/03 14:00:14 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

double		ft_pow(double num, int pow)
{
	double	res;
	int		n;

	res = 1;
	if (!pow)
		return (1);
	if (pow < 0)
	{
		n = -1;
		pow *= -1;
	}
	else
		n = 1;
	while (pow != 0)
	{
		res *= num;
		pow--;
	}
	if (n < 0)
		return (1 / res);
	else
		return (res);
}
