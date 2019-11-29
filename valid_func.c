/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:26:04 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/29 22:01:49 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_binarysquare(char *tetr)
{
	int	byte;

	byte = 0;
	while (*tetr)
	{
		byte = (*tetr == '#') ? (byte | 1) << 1 : byte << 1;
		tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
	}
	byte = byte >> 1;
	return (byte);
}

int		ft_definition(int *byte, int fd)
{
	char		*c;
	char		r;
	int			num;

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
	if ((*byte = ft_binarysquare(c)) == -1)
		return (ft_newstrdel(&c));
	if (adjacency_counter(*byte) != 1)
		return (ft_newstrdel(&c));
	*byte = ft_shift(*byte);
	ft_newstrdel(&c);
	return (num);
}
