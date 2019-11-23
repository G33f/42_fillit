/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:29:24 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/14 22:29:28 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmat(const char **mat)
{
	if (!mat)
		return ;
	while(*mat)
	{
		ft_putstr(*mat);
		ft_putchar('\n');
		mat++;
	}
}
