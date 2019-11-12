/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:20:24 by wpoudre           #+#    #+#             */
/*   Updated: 2019/09/15 16:20:27 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_clean(char **str, int i)
{
	while (i >= 0)
	{
		free((*str + i));
		i--;
	}
	free(str);
}

static	int		ft_len(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			l;
	char		**str;

	if (!s || !(str = (char **)malloc(sizeof(str) * (ft_cu_wards(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_cu_wards(s, c))
	{
		l = 0;
		if (!(str[i] = ft_strnew(ft_len(&s[j], c) + 1)))
		{
			ft_clean(str, i);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][l++] = s[j++];
		str[i][l] = '\0';
	}
	str[i] = 0;
	return (str);
}
