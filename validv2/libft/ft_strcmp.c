/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:30:03 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/08 14:14:01 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*st1;
	unsigned char	*st2;
	int				i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((st1[i] == st2[i]) && (st1[i] || st2[i]))
		i++;
	return (st1[i] - st2[i]);
}
