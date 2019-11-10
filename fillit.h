/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:07:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/10 20:31:22 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

# define SIZE	16
# define SIZE_R	20
# define COORD	8

typedef struct		s_tetr
{
	int				*coordinates;
	int				*line;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

void				ft_putnubrs(int *mas, int len);
t_tetr				*ft_newtetr(int len, int crds);
int					ft_newstrdel(char **s);
int					ft_validsquare(char *tetr);
int					ft_binarysquare(char *tetr, t_tetr **ptr);
int					ft_definition(t_tetr **ptr, int fd);

#endif