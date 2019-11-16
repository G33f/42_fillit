/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:46:06 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/12 20:46:09 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_matdel(char ***as, int i)
{
	if (!as || !*as || !**as)
		return ;
	while(i)
	{
		ft_strdel(as[i]);
		i--;
	}
	free(**as);
	**as = 0;
}
