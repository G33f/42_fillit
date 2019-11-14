/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:30:33 by wpoudre           #+#    #+#             */
/*   Updated: 2019/11/12 16:30:36 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include "../libft/libft.h"
#include "torch.c"
#icnlude "logic.c"

typedef struct			s_tetrimino
{
	size_t				numb;
	char				**content;
	struct tetrimino	*next;
	size_t				x;
	size_t				y;
}						tetrimino;

#endif