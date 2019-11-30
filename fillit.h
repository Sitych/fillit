/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:07:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 09:00:13 by qjosmyn          ###   ########.fr       */
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



void	ft_print(int len, int i);
#endif
