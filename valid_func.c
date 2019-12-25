/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:26:04 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/25 22:16:39 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			adjacency_counter(byte b)
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

byte	ft_shift(byte b)
{
	while ((b & 0b1000100010001000) == 0)
		b = b << 1;
	while ((b & 0b1111000000000000) == 0)
		b = b << 4;
	return (b);
}

byte	ft_binarysquare(char *tetr)
{
	int	b;

	b = 0;
	while (*tetr)
	{
		b = (*tetr == '#') ? (b | 1) << 1 : b << 1;
		tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
	}
	b = b >> 1;
	return ((byte)b);
}

int		ft_definition(int *b, int fd)
{
	char		*c;
	char		r;
	int			num;

	c = ft_strnew(SIZE_R);
	num = read(fd, c, SIZE_R);
	if (num < 0)
		return (ft_newstrdel(&c));
	c[SIZE_R] = 0;
	// if (ft_validsquare(c) == -1)
	// 	return (ft_newstrdel(&c));
	num = read(fd, &r, 1);
	if (r != '\n' && r != 0)
		return (ft_newstrdel(&c));
	if ((*b = ft_binarysquare(c)) == -1)
		return (ft_newstrdel(&c));
	// if (adjacency_counter(*b) != 1)
	// 	return (ft_newstrdel(&c));
	*b = ft_shift(*b);
	ft_newstrdel(&c);
	return (num);
}
