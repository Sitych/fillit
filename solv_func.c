/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:26:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 02:27:01 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

byte		*ft_mapcreate(int quantity)
{
	int			i;
	byte		*map;

	if ((map = (byte*)malloc(sizeof(byte) * (quantity + 1))) == NULL)
		return (NULL);
	i = 0;
	printf("%d\n", quantity);
	while (i < quantity)
		map[i++] = 0b1000000000000000 >> quantity;
	map[i] = 0xffff;
	return (map);
}
