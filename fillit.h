/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:07:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/15 19:24:01 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define SIZE	16
# define SIZE_R	20
# define COORD	8
# define VALID	"valid_tetrominos"
# define K(i, j) (i * SIZE / 4 + j * SIZE / 4)

// # define I		(int[8]) {0,0,0,1,0,2,0,3}
// # define IH		(int[8]) {0,0,1,0,2,0,3,0}
// # define O		(int[8]) {0,0,1,0,0,1,1,1}
// # define L		(int[8]) {0,0,0,1,0,2,1,2}
// # define LR		(int[8]) {0,0,1,0,2,0,0,1}
// # define LRR	(int[8]) {0,0,1,0,2,0,0,1}
// # define LL		(int[8]) {2,0,0,1,1,1,2,1}
// # define S		(int[8]) {1,0,2,0,0,1,1,1}
// # define SR		(int[8]) {0,0,0,1,1,1,1,2}
// # define Z		(int[8]) {0,0,1,0,1,1,2,1}
// # define ZR		(int[8]) {1,0,0,1,1,1,0,2}
// # define T		(int[8]) {0,0,1,0,2,0,1,1}
// # define TL		(int[8]) {1,0,0,1,1,1,1,2}
// # define TR		(int[8]) {0,0,0,1,1,1,0,2}
// # define TRR	(int[8]) {1,0,0,1,1,1,2,1}
// # define J		(int[8]) {1,0,1,1,0,2,1,2}
// # define JR		(int[8]) {0,0,0,1,1,1,2,1}
// # define JRR	(int[8]) {0,0,1,0,2,0,2,1}
// # define JL		(int[8]) {0,0,1,0,1,1,1,2}

typedef struct		s_tetr
{
	int				*coords;
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
int					*ft_shift(int *mas);

#endif
