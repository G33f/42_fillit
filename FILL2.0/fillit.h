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
#include "libft/libft.h"
# include <fcntl.h>

tetrimino				*maintet(char *s);
char					**ft_add(char *s);
char					*ft_add_2(char *s, char *buf, int sim);
tetrimino				*ft_newtet(char **s, int x, int y, int numb);
int						ft_search(char *s);
int						ft_x(char *s);
int						ft_y(char *s);
int						lengt(tetrimino *tes);
int						valid(char **s);
int						vone(char *s, int *n, int *count);
int						ft_one(char *s, int i, int *m, int *count);
int						vtwo(char *s, char sim);
void					ft_two(char *s, int *i, int *count, char *sim);
int						ft_check(tetrimino *tes, char **cube, int i, int j);
char					**ft_newmat(char **cube, int i);
int						ft_logic(tetrimino *tes);
int						lengt(tetrimino *tes);
int						ft_starter(int fd);
char					put(tetrimino **tes, char **cube, int i,int j);
char					**ft_build(tetrimino *tes, char **cube, int leng);

#endif