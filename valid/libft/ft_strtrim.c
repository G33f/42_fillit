/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:35:12 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/11 17:57:19 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*st;
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	st = (char *)s;
	if (!st)
		return (NULL);
	while (*st == ' ' || *st == '\t' || *st == '\n')
		st++;
	len = ft_strlen(st) - 1;
	if (ft_strlen(st) == 0)
		return (new = ft_strnew(0));
	while (st[len] == ' ' || st[len] == '\t' || st[len] == '\n')
		len--;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	while (i <= len)
	{
		new[i] = st[i];
		i++;
	}
	return (new);
}
