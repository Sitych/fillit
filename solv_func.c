/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:26:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/29 22:08:33 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

uint16_t		*ft_mapcreate(int quantity)
{
	int			i;
	uint16_t	*map;

	if ((map = (uint16_t*)malloc(sizeof(uint16_t) * (quantity + 1))) == NULL)
		return (NULL);
	i = 0;
	printf("%d\n", quantity);
	while (i < (quantity))
		map[i++] = 1 << (sizeof(uint16_t) * 8 - quantity);
	map[i] = 0xffff;
	return (map);
}
