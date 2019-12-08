/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/08 09:02:56 by rretta           ###   ########.fr       */
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
	if (ptr == NULL)
		return (1);
	int		row;
	int		c;
	int		flag;

	row = 0;
	c = 0;
	flag = 0;
	while (row < len)
	{
		if (ft_place(&map, ptr, len, row) == 1)
		{
			if (ft_solver(ptr->next, map, len) == 1)
				return (1);
			else
				ft_place(&map, ptr, len, row + 1);
		}
		row++;
	}
	return (0);
}

int		ft_place(byte **map, t_tetr *ptr, int len, int row)
{
    int		i;
	int		j;
	byte	*old_map;

	old_map = ft_mapdup(*map, len);
    i = 0;
    while (i < len)
	{
		j = 0;
		while (j < 4)
		{
			(*map)[row + j] =  (*map)[row + j] ^ ptr->line[j];
			j++;
		}
		// printf("\nkek\n");
		ft_printmap(*map, len);
		if (ft_mapcheck(old_map, *map, len) == 1)
			return (1);
		j = 0;
		while (j < 4)
		{
			ptr->line[j] = ptr->line[j] >> 1;
			j++;
		}
		i++;
	}
	/*ft_freemap(new_map);*/
	*map = old_map;
	return (0);
}

int     ft_mapcheck(byte *old_map, byte *new_map, int len)
{
    int		i;
    int		s;

    i = 0;
    s = 0;
    while (i < len)
    {
    	/*if (((old_map[i] << i) >> len) == ((new_map[i] << i) >> len))*/
		if ((old_map[i] & new_map[i]) == old_map[i])
			s++;
		i++;
    }
	if (s == len - 1)
		return (1);
	return (0);
}