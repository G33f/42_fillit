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
# include "../libft/libft.h"
# include <fcntl.h>

t_tet					*ft_maintet(char *s);
char					**ft_add(char *s);
char					*ft_add_2(char *s, char *buf, int sim);
t_tet					*ft_newtet(char **s, int x, int y, int numb);
int						ft_search(char *s);
int						ft_x(char *s);
int						ft_y(char *s);
int						ft_valid(char **s);
int						ft_vone(char *s, int *count);
int						ft_one(char *s, int i, int *m, int *count);
int						ft_vtwo(char *s, char sim);
void					ft_two(char *s, int *i, int *count, char *sim);
int						ft_check(t_tet *tes, char **cube, int i, int j);
char					**ft_newmat(int numb);
int						ft_logic(t_tet *tes);
int						ft_lengt(t_tet *tes);
int						ft_starter(int fd);
int						ft_put(t_tet *tes, char **cube, int i, int j);
int						ft_build(t_tet *tes, char **cube, int leng);
int						ft_prover(char *s);
void					ft_fielddel(char **field, int i);
t_tet					*ft_freetet(t_tet *head);

#endif
