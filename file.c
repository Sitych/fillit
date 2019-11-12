/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/12 17:58:21 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"
#include <stdio.h>

void	ft_print(int *mas, int len)
{
	int i;

	i = 0;
	printf("{");
	while (i < len)
	{
		printf("%d,", mas[i]);
		i++;
	}
	printf("}\n");
}

int main(int ac, char **av)
{
	ac = 1;
	int fd = open(av[1], O_RDONLY);
	
	t_tetr	*ptr;
	t_tetr	*tmp;
	int num;

	num = 1;
	ptr = ft_newtetr(SIZE, COORD);
	// printf("%d", (ft_definition(&ptr, fd)));
	while (ft_definition(&ptr, fd))
	{
		tmp = ptr;
		ptr = ptr->next;
		ptr = ft_newtetr(SIZE, COORD);
		ptr->prev = tmp;
	}
	while (ptr->prev != NULL)
	{
		ft_print(ptr->coords, COORD);
		ptr = ptr->prev;
	}

	// ptr->next = ft_newtetr(SIZE, COORD);
	// ft_putnbr(ft_definition(&ptr, fd));
	// ft_putchar('\n');
	// ft_putnubrs(ptr->line, SIZE);
	// ft_putchar('\n');
	// ft_putnubrs(ptr->coords, SIZE / 2);

	// ft_putnbr(ft_definition(&ptr->next, fd));
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->line, SIZE);
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->coords, SIZE);
	close(fd);
	return (1);
}

int		*ft_shift(int *mas)
{
	int i;
	int x_min;
	int y_min;

	i = 0;
	x_min = mas[0];
	y_min = mas[1];
	while (i < COORD)
	{
		if (i % 2 == 0)
			x_min = (x_min < mas[i]) ? x_min : mas[i];
		else
			y_min = (y_min < mas[i]) ? y_min : mas[i];
		i++;
	}
	i = -1;
	while (i++ < COORD)
	{
		if (i % 2 == 0)
			mas[i] = mas[i] - x_min;
		else
			mas[i] = mas[i] - y_min;
	}
	return (mas);
}

int		ft_validsquare(char *tetr)
{
	int		i;
	
	i = 0;
	while (i < SIZE)
	{
		if (*(tetr++) == '\n' && i % 4 == 0)
			continue ;
		if (*(tetr - 1) != '.' && *(tetr - 1) != '#')
			return (-1);
		i++;
	}
	return (1);
}

int		ft_binarysquare(char *tetr, t_tetr **ptr)
{
	int	i;
	int	j;

	if (*ptr == NULL)
		return (-1);
	i = 0;
	while (i < SIZE / 4)
	{
		j = 0;
		while (j < SIZE / 4)
		{
			(*ptr)->line[i * SIZE / 4 + j] = (*tetr == '.') ? 0 : 1;
			if (*tetr != '.')
			{
				*((*ptr)->coords++) = j;
				*((*ptr)->coords++) = i;
			}
			tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
			j++;
		}
		i++;
	}
	(*ptr)->coords = (*ptr)->coords - COORD;
	return (1);
}

int		ft_valid_tetr(t_tetr *inside)
{
	int		fd;
	int		i;
	int		flag;
	t_tetr	*ptr;
	t_tetr	*tmp;

	fd = open(VALID, O_RDONLY);
	ptr = ft_newtetr(SIZE, COORD);
	while (ft_definition(&ptr, fd))
	{
		tmp = ptr;
		ptr = ptr->next;
		ptr = ft_newtetr(SIZE, COORD);
		ptr->prev = tmp;
	}
	i = 0;
	while (ptr!= NULL)
	{
		flag = 0;
		while (i < COORD)
		{
			flag = (ptr->coords[i] == inside->coords[i]) ? flag++ : 0;
			i++;
		}
		if (flag == COORD)
			return (1);
		ptr = ptr->prev;
	}
	return (-1);
}

int		ft_definition(t_tetr **ptr, int fd)
{
	char	*c;
	char	r;
	int		num;

	c = ft_strnew(SIZE_R);
	num = read(fd, c, SIZE_R);
	if (num < 0)
		return (ft_newstrdel(&c));
	c[SIZE_R] = 0;
	if (ft_validsquare(c) == -1)
		return (ft_newstrdel(&c));
	num = read(fd, &r, 1);
	if (r != '\n' && r != 0)
		return (ft_newstrdel(&c));
	if (ft_binarysquare(c, ptr) == -1)
		return (ft_newstrdel(&c));
	ft_newstrdel(&c);
	(*ptr)->coords = ft_shift((*ptr)->coords);
	return (num);
}