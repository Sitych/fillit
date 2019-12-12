/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:18:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/12 01:39:50 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < 2147483647)
	{
		if ((i * i) < nb)
			i++;
		else if ((i * i) >= nb)
			return (i);
	}
	return (0);
}

byte		*ft_mapcreate(int quantity)
{
	int			i;
	byte		*map;

	if ((map = (byte*)malloc(sizeof(byte) * (quantity + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < quantity)
		map[i++] = 0xffff >> quantity;
	map[i] = 0xffff;
	return (map);
}

byte		*ft_mapdup(byte *map, int len)
{
	int		i;
	byte	*copymap;

	if ((copymap = (byte*)malloc(sizeof(byte) * len)) == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copymap[i] = map[i];
		i++;
	}
	return (copymap);
}
