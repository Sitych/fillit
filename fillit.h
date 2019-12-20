/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:07:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/21 00:49:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define SIZE	16
# define SIZE_R	20
# define COORD	8

typedef unsigned short int	byte;

typedef struct				s_tetr
{
	byte					*line;
	char					c;
	byte					*tetromin;
	struct s_tetr			*next;
	struct s_tetr			*prev;
}							t_tetr;

void						ft_putnubrs(int *mas, int len);
t_tetr						*ft_newtetr(int byte, char c);
int							ft_newstrdel(char **s);
int							ft_validsquare(char *tetr);
byte						ft_binarysquare(char *tetr);
int							ft_definition(int *b, int fd);
unsigned int				ft_to_binary(int *mas);
int							adjacency_counter(byte b);
byte						ft_shift(byte b);
int							ft_listlen(t_tetr *ptr);
byte						*ft_mapcreate(int quantity);
int							ft_sqrt(int nb);
int							ft_solve(t_tetr *ptr, int len);
byte						*ft_mapdup(byte *map, int len);
int     					ft_mapcheck(byte *old_map, byte *new_map, int len);
int							ft_place(byte **map, t_tetr *ptr, int len, int row);
int     					ft_solver(t_tetr *ptr, byte *map, int len);
t_tetr						*ft_shift_tetr(t_tetr *tmp, int direction, int quantity);
byte						*ft_mapcopy(byte *map, byte *old_map, int len);
byte						*ft_xormap(byte *map, t_tetr *ptr, int row);
int							ft_sqrt(int nb);
byte						*ft_null_tetramin(byte *tetramin);
char						**ft_charmapcreate(void);
int		ft_print_tetr(t_tetr *ptr, int len);
char		**ft_charmapcreate(int len);

void	ft_print(int len, int i);
#endif
