/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:26:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/08 07:51:16 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "fillit.h"

int			ft_kostyl(t_tetr ptr, int len)
{
	
	int 	k;
	int		j;
	k = 0;
	while (ptr != NULL)
	{
		j = 0;
		while (j < 4)
		{
			ft_print(ptr->line[j], 0);
			j++;
			ft_putchar('\n');
		}
		ptr = ptr->next;
	}
	
	k = 0;
	while (i <= len)
	{
		ft_print(map[k], 0);
		ft_putchar('\n');
		k++;
	}
}

int			ft_solve(t_tetr *ptr, int len, byte *map)
{
	byte	*copymap;
	int		i;
	int		j;

	copymap = ft_mapdup(map, len);
	i = 0;
	while (i < len)
	{
		j = i;
		
			while (j < i + 4)
			{
				map[j] = map[j] ^ ptr->line[j];
				j++;
			}
		i++;
	}
	return (0);
}*/