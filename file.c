/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/17 21:32:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"
#include <stdio.h>

// typedef int    (*t_ft_print_dispatch_f)(const char *fmt, va_list ap, int
//         curr_chr, int len);
// static    t_ft_print_dispatch_f const g_ft_print_dispatch[256] =
// {
//     ['%'] = ft_print_percent,
//     ['c'] = ft_print_c,
//     ['s'] = ft_print_s,
//     ['p'] = ft_print_p,
//     ['f'] = ft_print_f,
//     ['d'] = ft_print_d,
//     ['i'] = ft_print_d,
//     ['o'] = ft_print_o,
//     ['u'] = ft_print_u,
//     ['x'] = ft_print_x,
//     ['X'] = ft_print_bigx,
// };

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
	while (ft_definition(&ptr, fd) > 0)
	{
		//ft_putnbr(num);
		tmp = ptr;
		ptr = ptr->next;
		ptr = ft_newtetr(SIZE, COORD);
		ptr->prev = tmp;
	}
	// int mas[19] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};

	while (1)
	{
		ft_putnubrs(ptr->line, SIZE);
		ft_putchar('\n');
		printf("valid tetr = %d\n", adjacency_counter(ptr->line));
		if (ptr->prev == NULL)
			break ;
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

int             ft_validsquare(char *tetr)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < SIZE)
	{
		if (*(tetr++) == '\n' && i % 4 == 0)
				continue ;
		if (*(tetr - 1) != '.' && *(tetr - 1) != '#')
				return (-1);
		if (*(tetr - 1) == '#')
			k++;
		i++;
	}
	if (k != 4)
		return (-1);
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

int        adjacency_counter(int *buf)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < 19)
    {
        if (buf[i] == 1)
        {
            if (i + 1 <= 18 && buf[i + 1] == 1)
                count++;
            if (i - 1 >= 0 && buf[i - 1] == 1)
                count++;
            if (i + 4 <= 18 && buf[i + 4] == 1)
                count++;
            if (i - 4 >= 0 && buf[i - 4] == 1)
                count++;
        }
        i++;
    }
	printf("count = %d ", count);
    return (count == 6 || count == 8);
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
	(*ptr)->coords = ft_shift((*ptr)->coords);
	// printf("\n valid tetr = %d\n", adjacency_counter((*ptr)->line));
	// if (adjacency_counter((*ptr)->line) != 0)
	// 	return (ft_newstrdel(&c));
	ft_newstrdel(&c);
	return (num);
}