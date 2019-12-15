/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/15 23:20:15 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 

void	ft_printmap(byte *map, int len)
{
	int k;
		
	k = 0;
	while (k <= len)
	{
		ft_print(map[k], 0);
		ft_putchar('\n');
		k++;
	}
}

int     ft_solver(t_tetr *ptr, byte *map, int len)
{
	ft_printmap(map, len);
	printf("\n");
	if (ptr == NULL)
		return (1);
	int		row;
	int		c;

	
	row = 0;
	c = 0;
	while (row < len)
	{
		if (ft_place(&map, ptr, len, row) == 0)
		{
			row++;
		}
		else 
			if (ft_solver(ptr->next, map, len) == 1)
				return (1);
	}
	return (0);
}

int		ft_place(byte **map, t_tetr *ptr, int len, int row)
{
    int		i;
	byte	*old_map;

	old_map = ft_mapdup(*map, len);
	i = 0;
	while (i < len)
	{
		*map = ft_xormap(*map, ptr, row);
		// printf("map\n");
		// ft_printmap(*map, len);
		// printf("\nold_map\n");
		// ft_printmap(old_map, len);
		// printf("\n");
		if (ft_mapcheck(old_map, *map, len) == 1)
		{
			ptr = ft_shift_tetr(ptr, -1, i);
			return (1);
		}
		*map = ft_mapcopy(*map, old_map, len);
		ptr = ft_shift_tetr(ptr, 1, 1);
		i++;
	}
	ptr = ft_shift_tetr(ptr, -1, len);
	/*ft_freemap(new_map);*/
	return (0);
}

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
