/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/10 20:58:06 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"

int main(int ac, char **av)
{
	ac = 1;
	int fd = open(av[1], O_RDONLY);
	t_tetr *ptr = NULL;

	ptr = ft_newtetr(SIZE, COORD);
	ptr->next = ft_newtetr(SIZE, COORD);
	ft_putnbr(ft_definition(&ptr, fd));
	ft_putchar('\n');
	ft_putnubrs(ptr->line, SIZE);
	ft_putchar('\n');
	ft_putnubrs(ptr->coordinates, SIZE / 2);

	// ft_putnbr(ft_definition(&ptr->next, fd));
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->line, SIZE);
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->coordinates, SIZE);
	// close(fd);
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
				*((*ptr)->coordinates++) = j;
				*((*ptr)->coordinates++) = i;
			}
			tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
			j++;
		}
		i++;
	}
	(*ptr)->coordinates = (*ptr)->coordinates - COORD;
	return (1);
}

int		ft_definition(t_tetr **ptr, int fd)
{
	char	*c;
	char	r;
	int		num;

	c = ft_strnew(SIZE_R);
	if (read(fd, c, SIZE_R) < 0)
		return (ft_newstrdel(&c));
	c[SIZE_R] = 0;
	if (ft_validsquare(c) == -1)
		return (ft_newstrdel(&c));
	num = read(fd, &r, 1);
	if (r != '\n')
		return (ft_newstrdel(&c));
	if (ft_binarysquare(c, ptr) == -1)
		return (ft_newstrdel(&c));
	ft_newstrdel(&c);
	(*ptr)->coordinates = ft_shift((*ptr)->coordinates);
	return (num);
}