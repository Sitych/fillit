/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/21 00:51:05 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"
#include "valid_func.c"
#include "map_func.c"
#include <stdio.h>
#include "solver.c"

void	ft_print(int len, int i)
{
	if (len < 2)
	{
		while (i < 15)
		{
			ft_putchar('0');
			i++;
		}
		ft_putchar('0' + len);
		return ;
	}
	i++;
	ft_print(len / 2, i);
	ft_putchar('0' + len % 2);
	return ;
}

int main(int ac, char **av)
{
	t_tetr	*ptr;
	t_tetr	*tmp;
	t_tetr	*start;
	int		num;
	char	c;
	int		fd;
	int len;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || ft_definition(&num, fd) == -1)
		return (0);
	c = 'A';
	ptr = ft_newtetr(num, c++);
	start = ptr;
	while (ft_definition(&num, fd) > 0)
	{
		tmp = ptr;
		ptr->next = ft_newtetr(num,c++);
		ptr = ptr->next;
		ptr->prev = tmp;
	}
	ptr->next = ft_newtetr(num,c++);
	ptr = ptr->next;

	byte *map;
	len = ft_sqrt(ft_listlen(start) * 4);
	map = ft_mapcreate(len);
	ptr = start;
	while (!ft_solver(start, map, len))
	{
		ptr = start;
		while (ptr != NULL)
		{
			ptr->tetromin = ft_null_tetramin(ptr->tetromin);
			ptr = ptr->next;
		}
		len++;
		map = ft_mapcreate(len);
		ptr = start;
	}
	ptr = start;
	ft_putstr("START\n");
	while (ptr != NULL)
	{
		ft_printmap(ptr->tetromin, 13);
		printf("\n");
		ptr = ptr->next;
	}
	//	ft_print_tetr(start, len);

	close(fd);
	return (1);
}
