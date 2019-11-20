/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/19 11:31:14 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

char			**maintet(char *s)
{
	char		*buf;
	char		*hmm;
	int			sim;
	int			count;
	int			i;

	i = 0;
	count = 0;
	buf = ft_strnew(10);
	hmm = ft_strnew(1);
	while (s[i] && i < ft_strlen(s))
	{
		hmm = ft_strjoin(hmm, ft_add(&s[i], buf, sim));
		while (buf[count])
			buf[count++] = '\0';
		count = 0;
		i += 21;
	}
	free(buf);
	return (ft_strsplit(hmm, '\n'));
}

char			*ft_add(char *s, char *buf, int sim)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i] && i < 20)
	{
		if ((sim = ft_search(&s[i])))
		{
			while (s[i] && s[i] != '\n')
			{
				if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
					buf[j++] = s[i];
				else if (s[i - 5] == sim || s[i - 10] == sim)
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
			sim = 0;
			i++;
		}
		else
			i += 5;
	}
	return (buf);
}
