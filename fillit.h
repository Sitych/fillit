/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:07:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/29 20:23:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define SIZE	16
# define SIZE_R	20
# define COORD	8
typedef struct		s_tetr
{
	int				line;
	char			c;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

void				ft_putnubrs(int *mas, int len);
t_tetr				*ft_newtetr(int byte, char c);
int					ft_newstrdel(char **s);
int					ft_validsquare(char *tetr);
int					ft_binarysquare(char *tetr);
int					ft_definition(int *byte, int fd);
unsigned int		ft_to_binary(int *mas);
int					adjacency_counter(unsigned int b);
int					ft_shift(int byte);
int					ft_listlen(t_tetr *ptr);

#endif
