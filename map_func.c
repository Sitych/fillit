/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:18:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/30 19:36:21 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int     ft_mapcheck(byte *map, t_tetr *ptr, int len)
{
    int		i;

    i = 0;
    while (i < len)
    {
		if ((map[i] & ptr->tetromin[i]) != 0)
			return (0);
		i++;
    }
	return (1);
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

byte		*ft_mapcopy(byte *map, byte *old_map, int len)
{
	int		i;

	i = 0;
	while (i <= len)
	{
		map[i] = old_map[i];
		i++;
	}
	return (map);
}

byte		*ft_xormap(byte *map, t_tetr *ptr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		map[i] = map[i] ^ ptr->tetromin[i];
		i++;
	}
	return (map);
}
