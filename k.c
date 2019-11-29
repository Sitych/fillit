/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:26:04 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/29 17:56:40 by qjosmyn          ###   ########.fr       */
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

uint16_t			adjacency_counter(uint16_t b)
{
	int				count;
	int				i;
	uint16_t		tmp;

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

uint16_t		ft_shift(uint16_t byte)
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
