/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/28 18:30:33 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit1.h"
#include "t_tetr_func.c"
#include <stdio.h>

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
	ac = 1;
	int fd = open(av[1], O_RDONLY);
	
	t_tetr	*ptr;
	t_tetr	*tmp;
	int num;

	num = 1;
	ptr = ft_newtetr(SIZE, COORD);
	// printf("def = %d", (ft_definition(&ptr, fd)));
	while (ft_definition(&ptr, fd) > 0)
	{
		num++;
		tmp = ptr;
		ptr = ptr->next;
		ptr = ft_newtetr(SIZE, COORD);
		ptr->prev = tmp;
	}
	while (1)
	{
		printf("tetr = %x %d\n", ptr->line, ptr->line);
		ft_print(ptr->line, 0);
		ft_putchar('\n');
		ptr->line = ft_shift(ptr->line);
		printf("shift byte =");
		ft_print(ptr->line, 0);
		ft_putchar('\n');
		printf("valid tetr = %d \n", adjacency_counter(ptr->line));
		if (ptr->prev == NULL)
			break ;
		ptr = ptr->prev;
	}

	ft_putnbr(num);
	// int b;
	// b = 0b1000100010001000;  // Или любое другое
	// ft_putchar('\n');
	// ft_print(b);
	
	close(fd);
	return (1);
}

int			adjacency_counter(unsigned int b)
{
	int				count;
	int				i;
	unsigned int	tmp;

	count = 0;
	i = 0;
	tmp = b;
	while (tmp != 0)
	{
		if (tmp & 0x80000000)
		{
			if (tmp & 0x40000000)
				count++;
			if (tmp & 0x08000000)
				count++;
			if (i > 0 && (b << (i - 1) & 0x80000000))
				count++;
			if (i > 4 && (b << (i - 4) & 0x80000000))
				count++;
		}
		i++;
		tmp = tmp << 1;
	}
	return (count == 6 || count == 8);
}

int		ft_shift(int byte)
{
	while ((byte & 0b1000100010001000) == 0)
		byte = byte << 1;
	while ((byte & 0b1111000000000000) == 0)
		byte = byte << 4;
	return (byte);
}

int		ft_binarysquare(char *tetr, t_tetr **ptr)
{
	if (*ptr == NULL)
		return (-1);
	while (*tetr)
	{
		(*ptr)->line = (*tetr == '#') ? ((*ptr)->line | 1) << 1 : (*ptr)->line << 1;
		tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
	}
	(*ptr)->line = (*ptr)->line >> 1;
	return (1);
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
	if (adjacency_counter((*ptr)->line) != 1)
		return (ft_newstrdel(&c));
	ft_newstrdel(&c);
	return (num);
}