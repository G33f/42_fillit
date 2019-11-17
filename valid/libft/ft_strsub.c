/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:42:33 by tzenz             #+#    #+#             */
/*   Updated: 2019/09/17 18:42:27 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		new[i++] = s[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}
