/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/05 20:25:36 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define SIZE 16
typedef struct	s_tetr
{
	int				*line;
	int				x;
	int				y;
	struct s_tetr	*next;
}				t_tetr;

int		ft_new_tetr(t_tetr **ptr, int fd)
{
	int		i;
	char	c;
	int		num;

	if (((*ptr)->line = (int*)ft_memalloc(sizeof(int) * SIZE)) == NULL)
		return (-1);
	i = 0;
	while (i <= SIZE)
	{
		if (read(fd, &c, 1) < 0)
			return (-1);
		if (c == '\n' && i % 4 == 0)
			continue ;
		if (c != '.' || c != '#')
			retutn (-1);
		(*ptr)->line[i] = (c == '.') ? 0 : 1;
		i++;
	}
	num = read(fd, &c, 1);
	if (c != '\n' || i < SIZE)
		return (-1);
	return (num);
}